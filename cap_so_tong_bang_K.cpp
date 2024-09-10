#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(vector<int> &v, int n, int k){
    unordered_map<int, int> mp;
    int cnt = 0;
    for(int it : v){
        if(mp[k - it] > 0){
            cnt += mp[k - it];
        }
        mp[it]++;
    }
    cout << cnt << endl;
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
        solve(v, n, k);
    }
    return 0;
}
/* No Code - No Bug */