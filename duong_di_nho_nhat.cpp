#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MAX));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i  - 1][j - 1]}) + matrix[i][j];
        }
    }
    cout << dp[n][m] << endl;
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