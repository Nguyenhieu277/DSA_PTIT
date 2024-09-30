#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.size() + 1, vector<int> (str2.size() + 1, 0));
    for(int i = 0; i <= str1.size(); i++){
        for(int j = 0; j <= str2.size(); j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    cout << dp[str1.size()][str2.size()] << endl;
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