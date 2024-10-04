#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll dp[max_n][max_n];
void init(){
    for(int i = 0; i < max_n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
}
void TestCase(){
    int n;
    cin >> n;
    cout << dp[n + 9][n] << endl;
}
int main(){
    Quick();
    init();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */