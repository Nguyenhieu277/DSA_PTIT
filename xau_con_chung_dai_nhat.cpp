#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int dp[max_n][max_n];
void LCS(string s, string t){
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }      
    }
    cout << dp[s.size()][t.size()] << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        LCS(s, t);
    }
    return 0;
}
/* No Code - No Bug */