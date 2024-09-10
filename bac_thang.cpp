#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicAlgorithm(int n, int k){
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i >= j){
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n] << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        dynamicAlgorithm(n, k);
    }
    return 0;
}
/* No Code - No Bug */