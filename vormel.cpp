#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;
int main() {
    cin>>M>>N>>K;
    // Loo massiv ringiaegadele
    N = N*2;
    int **a = new int*[M];
    int **s = new int*[M];
    for (int i = 0; i < M; ++i) {
        a[i] = new int[N];
        s[i] = new int[N];
    }


    // Loe sisse ja täida
    for (int i = 0; i < M; ++i) {
        int r, d;
        cin>>r>>d;
        a[i][0]=r;
        s[i][0]=0;
        int kparim = 0;
        int lisakordaja = 1;
        int viimane_vahetus = INT32_MIN;
        for (int j = 1; j < N; ++j) {
            s[i][j] = s[i][j-1];
            int u = a[i][j-1] + r + lisakordaja * d;

            lisakordaja++;
            int k = j;
            int v = INT32_MAX;
            // k > viimane_vahetus
            while (k > 0 && k >  viimane_vahetus) {
                int vtmp = a[i][k-1] + a[i][j-k] + K;
                if(vtmp < v){
                    v = a[i][k-1] + a[i][j-k] + K;
                    kparim = k;
                }
                k--;
            }

            // Kui teha vahetus, kohal mille eelduseks oli mingi muu vahetus, siis seda teha ei tohi !!!
            // Mida perset. seega  s[i][kparim] == s[i][kparim-1]
            if(v < u && s[i][kparim] == s[i][kparim-1]){
                // k kohal vahetus k=0,k+1=1
                s[i][j] = kparim;
                lisakordaja = j - kparim + 1;
                viimane_vahetus = kparim;
                u = v;
            }
            a[i][j]= u;
        }

    }



    cout<<endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<< j+1 << " " <<a[i][j]<<" " << s[i][j]+1 <<endl;
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