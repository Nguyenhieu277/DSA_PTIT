#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 501
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void TestCase(){
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(max_n, vector<int>(max_n, 0));
    int maxVal = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                dp[i][j] = 0;
            }
            else{
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
            maxVal = max(maxVal, dp[i][j]);
        }
    }
    cout << maxVal << endl;

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