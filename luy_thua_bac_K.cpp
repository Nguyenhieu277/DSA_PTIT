#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<vector<ll>> dp(1001, vector<ll> (mod + 1, 0));
ll binPow(ll a, ll n){
    ll res = 1;
    while(n > 0){
        if(n % 2 == 0){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}
void init(){
    for(int k = 0; k <= 1000; k++){
        for(int i = 1; i <= mod; i++){
            dp[k][i] = binPow(i, k);
        }
    }
}
void TestCase(){
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    if(n <= mod){
        for(ll i = 1; i <= n; i++){
            res = (res + dp[k][i]) % mod;
        }
    }
    else{
        for(ll i = 1; i <= mod; i++){
            res = (res + dp[k][i]) % mod;
        }
        res = (res * (n / mod)) % mod;
        for(ll i = 1; i <= n % mod; i++){
            res = (res + dp[k][i]) % mod;
        }
    }
    cout << res << endl;
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