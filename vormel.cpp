#include <iostream>
using namespace std;

int M, N, K;
int main() {
    cin>>M>>N>>K;
    int **a = new int*[M];
    for (int i = 0; i < M; ++i) {
        a[i] = new int[N];
    }
    for (int i = 0; i < M; ++i) {
        int r, d;
        cin>>r>>d;
        a[i][0]=r;
        for (int j = 1; j < N; ++j) {
            a[i][j]= a[i][j-1] + r + j * d;
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
