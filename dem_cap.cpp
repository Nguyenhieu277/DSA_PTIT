#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int solve(vector<int> &v, vector<int> &count, int x){
    if(x == 0) return 0;
    if(x == 1) return count[0];
    auto ans = v.end() - upper_bound(v.begin(), v.end(), x);
    ans += count[1] + count[0];
    if(x == 2) ans -= count[3] + count[4];
    if(x == 3) ans += count[2];
    return ans;
} 
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v1, v2;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v1.push_back(x);
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            v2.push_back(x);
        }
        sort(v2.begin(), v2.end());
        vector<int> count(max_n, 0); // gtri dac biet be hon 5 can xu li
        for(int it : v2){
            if(it < 5) count[it]++;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += solve(v2, count, v1[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
/* No Code - No Bug */