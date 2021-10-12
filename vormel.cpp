#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;
int main() {
    cin>>M>>N>>K;
    // Loo massiv ringiaegadele
    int **a = new int*[M];
    for (int i = 0; i < M; ++i) {
        a[i] = new int[N];
    }

    // Loe sisse ja täida
    for (int i = 0; i < M; ++i) {
        int r, d;
        cin>>r>>d;
        a[i][0]=r;
        for (int j = 1; j < N; ++j) {
            int u = a[i][j-1] + r + j * d;

            int k = j;
            int kprm = 0;
            int v = INT32_MAX;
            while (k > 0) {
                int vtmp = a[i][k-1] + a[i][j-k] + K;
                if(vtmp < v){
                    v = a[i][k-1] + a[i][j-k] + K;
                    kprm = k + 1;
                }
                k--;
            }
            if(v<u){
                cout<<"Leidsime "<< i << " "<<j << " " << kprm;
            }
            a[i][j]= std::min(u, v);
        }
    }




    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Juhhei!";

}
