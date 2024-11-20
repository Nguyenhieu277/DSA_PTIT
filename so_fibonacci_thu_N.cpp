#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Matrix{
    ll matrix[2][2];
    friend Matrix operator * (Matrix a, Matrix b){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.matrix[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    res.matrix[i][j] += (a.matrix[i][k] * b.matrix[k][j]) % mod;
                }
                res.matrix[i][j] %= mod;
            }
        }
        return res;
    };
};
Matrix binPow(Matrix a, ll n){
    if(n == 1){
        return a;
    }
    Matrix k = binPow(a, n / 2);
    if(n & 1){
        return k * k * a;
    }
    else return k * k;
}
Matrix a;
void TestCase(){
    ll n;
    cin >> n;
    Matrix res = binPow(a, n);
    cout << res.matrix[0][1] << endl;
}
int main(){
    Quick();
    a.matrix[0][0] = 1;
    a.matrix[0][1] = 1;
    a.matrix[1][0] = 1;
    a.matrix[1][1] = 0;
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */