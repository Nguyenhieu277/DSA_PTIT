#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void dynamicProgramming(vector<int> &v, int n){
    vector<int> dp(n + 1, 0);
    dp[0] = v[0];
    for(int i = 0; i < n; i++){
        dp[i] = v[i];
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                dp[i] = max(dp[i], v[i] + dp[j]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    dynamicProgramming(v, n);
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