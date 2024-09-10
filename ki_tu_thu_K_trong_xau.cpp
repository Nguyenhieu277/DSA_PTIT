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
    while(n != 0){
        if(n & 1){
            res *= a;
        }
        n >>= 1;
        a *= a;
    }
    return res;
}
char findCharacter(ll n, ll k){
    ll mid = binPow(2, n - 1);
    if(k == mid){
        return 'A' + n - 1;
    }
    if(k < mid){
        return findCharacter(n - 1, k);
    }
    else return findCharacter(n - 1, k - mid);
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << findCharacter(n, k) << endl;
    }
    return 0;
}
/* No Code - No Bug */