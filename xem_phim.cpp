#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicProgramming(vector<int> &v, int n, int c){
    int dp[n + 1][c + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + v[i]);
            }
        }
    }
    cout << dp[n][c] << endl;
}
int main(){
    Quick();
    int c, n;
    cin >> c >> n;
    vector<int> v(n);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    dynamicProgramming(v, n, c);
    return 0;
}
/* No Code - No Bug */