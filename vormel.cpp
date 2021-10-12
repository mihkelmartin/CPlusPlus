#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;
int main() {
    cin>>M>>N>>K;
    // Loo massiv ringiaegadele
    int **a = new int*[M];
    int **s = new int*[M];
    int **b = new int*[M];
    for (int i = 0; i < M; ++i) {
        a[i] = new int[N];
        s[i] = new int[N];
        b[i] = new int[2];
    }


    // Loe sisse ja täida
    for (int i = 0; i < M; ++i) {
        int r, d;
        cin>>r>>d;
        a[i][0]=r;
        s[i][0]=0;
        int rpv = 1;
        for (int j = 1; j < N; ++j) {
            s[i][j] = s[i][j-1];
            int u = a[i][j-1] + r + rpv * d;
            rpv++;

            int k = j;
            int kprm = 0;
            int v = INT32_MAX;
            while (k > 0) {
                int vtmp = a[i][k-1] + a[i][j-k] + K;
                if(vtmp < v){
                    v = a[i][k-1] + a[i][j-k] + K;
                    kprm = j - k + 1;
                }
                k--;
            }
            if(v<u){
                b[i][0] = kprm;
                s[i][j] = j;
                // Arv paremaid peale vahetust
                b[i][1] = j - kprm + 1;
                rpv = j - kprm + 1;
                u = v;
            }
            a[i][j]= u;
        }

    }



    cout<<endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<<a[i][j]<<" "<<endl;
            cout<<s[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<"Juhhei!";

}

/*
        if(bV){
            for (int j = 0; j < N; ++j) {
                a[i][j] = 0;
            }

            a[i][0]=r;
            int ring = 1;
            int vr = 1;
            while(ring < N){
                if(vr <= b[i][0]){
                    a[i][ring] = a[i][ring-1] + r + vr * d;
                    vr++;
                } else {
                    a[i][ring] = a[i][ring-1] + a[i][0] + K;
                    cout<<"Vahetus: " << ring << endl;
                    vr=1;
                }
                ring++;
            }
        }

 */