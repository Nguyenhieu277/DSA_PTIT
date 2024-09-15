#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void solve(vector<int> &v, int n, int k){
    ll ans = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++){
        int j = lower_bound(v.begin(), v.end(), k + v[i]) - v.begin();
        ans += (j - i - 1);
    }
    cout << ans << endl;
}
void TestCase(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    solve(v, n, k);
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