#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll binPow(ll a, ll n){
    ll res = 1;
    a %= mod;
    while(n != 0){
        if(n & 1){
            res *= (a % mod);
            res %= mod;
        }
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
int main(){
    Quick();  
    ll n, k;
    while(true){
        cin >> n >> k;
        if(n == 0 && k == 0){
            return 0;
        }
        cout << binPow(n, k) << endl;
    }
    return 0;
}
/* No Code - No Bug */