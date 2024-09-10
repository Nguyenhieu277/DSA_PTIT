#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int dp[max_n];
void LIS(vector<int> &v, int n){
     for(int i = 0; i < n; i++){
          dp[i] = 1;
     }
     for(int i = 1; i < n; i++){
          for(int j = 0; j < i; j++){
               if(v[i] >= v[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
               }
          }
     }
     cout << n - *max_element(dp, dp + n) << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        } 
        LIS(v, n);
    } 
    return 0;
}
/* No Code - No Bug */