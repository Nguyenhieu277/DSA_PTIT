#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


int TSP(vector<vector<int>>& matrix, vector<vector<int>>&dp, int n){
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 0; 
    }
    for(int currentMask = 1; currentMask < (1 << n); currentMask++){
        if(__builtin_popcount(currentMask) == 1) continue;
        else{
            for(int i = 0; i < n; i++){
                if(currentMask & (1 << i)){
                    dp[i][currentMask] = INT_MAX;
                    int prevMask = currentMask - (1 << i);
                    for(int j = 0; j < n; j++){
                        if(prevMask & (1 << j)){
                            dp[i][currentMask] = min(dp[i][currentMask], dp[j][prevMask] + matrix[i][j]);
                        }
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        ans = min(ans, dp[i][(1 << n) - 1]);
    }
    return ans;
}
void TestCase(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> ((1 << n), INT_MAX));   
    int result = TSP(matrix, dp, n);
    cout << result << endl;
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