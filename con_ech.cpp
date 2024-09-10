#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicProgramming(ll n){
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            if(i >= j){
                dp[i] = dp[i] + dp[i - j];
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
        ll n;
        cin >> n;
        dynamicProgramming(n);
    }
    return 0;
}
/* No Code - No Bug */