#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void Decode(string s){
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;
    for(int i = 2; i <= n; i++){
        int oneDigit = stoi(s.substr(i - 1, 1));
        int twoDigits = stoi(s.substr(i - 2, 2));
        if(oneDigit >= 1 && oneDigit < 10){
            dp[i] += dp[i - 1];
        }
        if(twoDigits >= 10 && twoDigits <= 26){
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[n] << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Decode(s);
    }
    return 0;
}
/* No Code - No Bug */