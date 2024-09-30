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
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(i >= nums[j]){
                dp[i] += dp[i - nums[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[k] << endl;
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