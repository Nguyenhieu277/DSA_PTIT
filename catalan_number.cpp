#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 101
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


ll dynamicProgramming(int n){
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}
void TestCase(){
    int n;
    cin >> n;
    cout << dynamicProgramming(n) << endl;
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