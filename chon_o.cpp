#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int bitMasks[16];
void initMask(){
    for(int mask = 0; mask < 16; mask++){
        int flag = 1;
        for(int i = 0; i < 3; i++){
            if((mask & (1 << i)) && (mask & (1 << (i + 1)))){
                flag = 0;
            }
        }
        bitMasks[mask] = flag;
    }
}
int solve(const int &col, const int &mask, const vector<vector<int>>& matrix){
    int score = 0;
    for(int row = 0; row < 4; row++){
        if(mask & (1 << row)){
            score += matrix[row][col];
        }
    }
    return score;
}
void selectCell(const vector<vector<int>>& matrix, const int& n){
    vector<vector<int>> dp(max_n, vector<int>(16, INT_MIN));
    for(int mask = 0; mask < 16; mask++){
        if(bitMasks[mask])
            dp[0][mask] = solve(0, mask, matrix);
    }
    int result = INT_MIN;
    for(int i = 1; i < n; i++){
        for(int currentMask = 0; currentMask < 16; currentMask++){
            dp[i][currentMask] = INT_MIN;
            if(bitMasks[currentMask]){
                int sum = solve(i, currentMask, matrix);
                for(int prevMask = 0; prevMask < 16; prevMask++){
                    if(bitMasks[prevMask] && ((currentMask & prevMask) == 0)){
                        dp[i][currentMask] = max(dp[i][currentMask], dp[i - 1][prevMask] + sum);
                    }
                }
            }
            result = max(result, dp[i][currentMask]);
        }
    }
    cout << result << endl;
}
void TestCase(){
    int n;
    cin >> n;
    int sum = INT_MIN;
    vector<vector<int>> matrix(4, vector<int> (max_n));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            sum = max(sum, matrix[i][j]);
        }
    }
    if(sum < 0) cout << sum << endl;
    else selectCell(matrix, n);
}
int main(){
    Quick();
    initMask();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */