#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 40001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicProgramming(vector<int> &v, int n, int s){
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = s; j >= v[i]; j--){
            if(dp[j - v[i]] == 1){
                dp[j] = 1;
            }
        }
    }
    if(dp[s]){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        dynamicProgramming(v, n, s);
    } 
    return 0;
}
/* No Code - No Bug */