#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Matrix{
    ll a[2][2];
    friend Matrix operator * (Matrix x, Matrix y){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    res.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    };
};
Matrix binPow(Matrix x, int n){
    if(n == 1){
        return x;
    }
    Matrix k = binPow(x, n / 2);
    if(n & 1){
        return k * k * x;
    }
    else return k * k;
}
Matrix matrix;
void init(){
    matrix.a[0][0] = matrix.a[0][1] = matrix.a[1][0] = 1;
    matrix.a[1][1] = 0;
}
void TestCase(){
    int n;
    cin >> n;
    Matrix res = binPow(matrix, n);
    cout << res.a[0][1] << endl;
}
int main(){
    Quick();
    init();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */