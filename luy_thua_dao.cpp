#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll binPow(ll a, ll n){
    if(n == 0){
        return 1;
    }
    ll x = binPow(a, n / 2);
    if(n & 1){
        return a * (x * x % mod) % mod;
    }
    else return x * x % mod;
}
ll Palindrome(ll n){
    ll res = 0;
    while(n != 0){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll tmp = Palindrome(n);
        cout << binPow(n, tmp) << endl;
    }
    return 0;
}
/* No Code - No Bug */