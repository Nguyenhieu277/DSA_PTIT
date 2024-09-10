#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int solve(vector<int> &v, int n, int k){
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < k; i++){
        sum1 += v[i];
    }
    for(int i = k; i < v.size(); i++){
        sum2 += v[i];
    }
    return sum2 - sum1;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        if(k <= n - k){
            cout << solve(v, n, k) << endl;
        }
        else{
            cout << solve(v, n, n - k) << endl;
        }
    }
    return 0;
}
/* No Code - No Bug */