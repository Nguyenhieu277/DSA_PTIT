#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll dp[max_n][max_n];
void init(){
    for(int i = 1; i < max_n; i++){
        dp[i][1] = i;
    }
    for(int i = 2; i < max_n; i++){
        for(int j = 2; j <= i; j++){
            dp[i][j] = i * dp[i - 1][j - 1] % mod;
        }
    }
}
void TestCase(){
    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << endl;
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