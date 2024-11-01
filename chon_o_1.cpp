#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int selectGrid(vector<vector<int>> &matrix, int n){
    int length = 1 << n;
    vector<int> dp(length, -1);
    dp[0] = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        int row = __builtin_popcount(mask);
        if(row >= n) continue;
        for(int col = 0; col < n; col++){
            if(!(mask & (1 << col))){
                int newMask = mask | (1 << col);
                dp[newMask] = max(dp[newMask], dp[mask] + matrix[row][col]);
            }
        }
    }
    return dp[length - 1];
}
void TestCase(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int> (n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    int result = selectGrid(matrix, n);
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