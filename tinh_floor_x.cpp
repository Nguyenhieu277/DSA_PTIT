#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n, k;
    cin >> n >> k;
    vector<ll> nums;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        nums.push_back(x);
    }
    auto it = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
    if(it <= 0) cout << -1 << endl;
    else cout << it << endl;
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