#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    string str;
    cin >> str;
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    vector<vector<int>> dp(str.size() + 1, vector<int> (str.size() + 1, 0));
    for(int i = 1; i <= str.size(); i++){
        for(int j = 1; j <= tmp.size(); j++){
            if(str[i - 1] == tmp[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << str.size() - dp[str.size()][tmp.size()] << endl;
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