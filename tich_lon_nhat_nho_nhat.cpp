#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll maxA = LONG_LONG_MIN, minB = LONG_LONG_MAX;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            maxA = max(maxA, x);
        }
        for(int i = 0; i < m; i++){
            ll x; cin >> x;
            minB = min(minB, x);
        }
        cout << maxA * minB << endl;
    }
    return 0;
}
/* No Code - No Bug */