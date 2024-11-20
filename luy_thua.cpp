#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll binPow(ll n, ll k){
    n %= mod;
    ll res = 1;
    while(k != 0){
        if(k & 1){
            res *= (n % mod);
            res %= mod;
        }
        k >>= 1;
        n = (n * n) % mod;
    }
    return res;
}
void TestCase(){
    ll n, k;
    cin >> n >> k;
    cout << binPow(n, k) << endl;
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