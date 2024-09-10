#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicProgramming(vector<int> &v, int n){
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum % 2 != 0){
        cout << "NO" << endl;
        return;
    }
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = target; j >= v[i]; j--){
            if(dp[j - v[i]] == 1){
                dp[j] = 1;
            }
        }
    }
    if(dp[target]){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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
        dynamicProgramming(v, n);
    }
    return 0;
}
/* No Code - No Bug */