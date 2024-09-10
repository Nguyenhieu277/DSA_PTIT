#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicProgramming(vector<int> &v, vector<int> &w, int n, int s){
    ll dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[n][s] << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> v(n + 1), w(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        dynamicProgramming(v, w, n, s);
    }
    return 0;
}
/* No Code - No Bug */