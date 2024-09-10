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
        int n;
        ll X;
        cin >> n >> X;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        auto it = upper_bound(v.begin(), v.end(), X) - v.begin();
        if(it <= 0) cout << -1 << endl;
        else{
            // --it;
            cout << it << endl;
        }
    }
    return 0;
}
/* No Code - No Bug */