#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
struct Matrix{
    ll a[10][10];
    
    friend Matrix operator * (Matrix x, Matrix y){
        Matrix res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < n; k++){
                    res.a[i][j] += ((x.a[i][k]) * (y.a[k][j]));
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    };
};
Matrix binPow(Matrix a, ll k){
    if(k == 1){
        return a;
    }
    Matrix tmp = binPow(a, k / 2);
    if(k & 1){
        return a * (tmp * tmp);
    }
    else return tmp * tmp;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> n >> k;
        Matrix matrix;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix.a[i][j];
            }
        }
        Matrix res = binPow(matrix, k);
        ll result = 0;
        for(int i = 0; i < n; i++){
            result = (result + res.a[i][n - 1]);
            result %= mod;
            
        }
        cout << result << endl;
    }
    return 0;
}
/* No Code - No Bug */