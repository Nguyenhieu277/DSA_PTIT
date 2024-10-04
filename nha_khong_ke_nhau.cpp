#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    if (n == 1) {
        cout << nums[0] << endl;
        return;
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    cout << dp[n - 1] << endl;
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