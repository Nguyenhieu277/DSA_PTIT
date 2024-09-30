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
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n] << endl;
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