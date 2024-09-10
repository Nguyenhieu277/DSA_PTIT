#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll dp[max_n][max_n];
void Ckn(int n, int k){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][k] << endl;
}
int main(){
    Quick();
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        Ckn(n, k);
    }
    return 0;
}
/* No Code - No Bug */