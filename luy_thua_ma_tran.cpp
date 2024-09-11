#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 11
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
struct Matrix{
    ll a[max_n][max_n];
    friend Matrix operator * (Matrix x, Matrix y){
        Matrix res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < n; k++){
                    res.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    };
};
Matrix binPow(Matrix x, int k){
    if(k == 1){
        return x;
    }
    Matrix tmp = binPow(x, k / 2);
    if(k & 1){
        return tmp * tmp * x;
    }
    else return tmp * tmp;
}
void TestCase(){
    int k;
    cin >> n >> k;
    Matrix matrix;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix.a[i][j];
        }
    }
    Matrix res = binPow(matrix, k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */