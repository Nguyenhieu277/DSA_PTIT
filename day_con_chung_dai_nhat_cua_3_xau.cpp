#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 101
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int dp[max_n][max_n][max_n];
void dynamicProgramming(string s1, string s2, string s3){
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            for(int k = 1; k <= s3.size(); k++){
                if(s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]){
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
                res = max(res, dp[i][j][k]);
            }
        }
    }
    cout << res << endl;
}
void TestCase(){
    int n, m, k;
    cin >> n >> m >> k;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    dynamicProgramming(s1, s2, s3);
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