#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int dp[max_n];
void init(){
    int i2 = 1, i3 = 1, i5 = 1;
    dp[1] = 1;
    for(int i = 2; i <= max_n; i++){
        dp[i] = min(min(dp[i2] * 2, dp[i3] * 3), dp[i5] * 5);
        if(dp[i] == dp[i2] * 2) i2++;
        if(dp[i] == dp[i3] * 3) i3++;
        if(dp[i] == dp[i5] * 5) i5++;
    }
}
void TestCase(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
int main(){
    Quick();
    init();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */