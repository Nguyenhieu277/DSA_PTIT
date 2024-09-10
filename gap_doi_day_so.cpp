#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll findElement(ll n, ll k){
    if(n == 1){
        return 1;
    }
    ll length = pow(2, n - 1);
    if(k == length){
        return n;
    }
    else if(k < length){
        return findElement(n - 1, k);
    }
    else return findElement(n - 1, k - length);
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << findElement(n, k) << endl;
    }
    return 0;
}
/* No Code - No Bug */