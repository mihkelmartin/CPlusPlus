#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;
int main() {
    cin>>M>>N>>K;
    // Loo massiv ringiaegadele
    int **a = new int*[M];
    // Loo massiiv vahetustele
    int **s = new int*[M];
    // Alusta
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


    int parim_rehv = -1;
    int parim_aeg = INT32_MAX;

    for (int i = 0; i < M; ++i) {
        if(a[i][N-1] < parim_aeg){
            parim_aeg = a[i][N-1];
            parim_rehv = i;
        }
    }
    int n = N-1;
    std::vector<int> v;
    while (s[parim_rehv][n] > 1){
        int vahetus = s[parim_rehv][n];
        // Igal ringil vahetus, siis sama
        if(vahetus == n){
            vahetus--;
        }
        v.insert(v.begin(), vahetus);
        n = vahetus;
    }
    cout << parim_rehv + 1 << " " << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
    {
        std::cout<<v[i]<< " " << parim_rehv + 1 << std::endl;
    }

    /*
    cout<<endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<< j+1 << " " <<a[i][j]<<" " << s[i][j]+1 <<endl;
        }
        cout<<endl;
    }
     */
}
