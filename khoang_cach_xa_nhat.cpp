#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void twoPointers(vector<pair<ll, ll>> &v, int n){
    ll res = -1;
    ll curr = v[0].second;
    for(int i = 1; i < n; i++){
       res = max(res, v[i].second - curr); 
       curr = min(curr, v[i].second);
    } 
    cout << res << endl;
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first < b.first;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll, ll>> v;
        for(int i = 1; i <= n; i++){
            ll x; cin >> x;
            v.push_back({x, i});
        }
        sort(v.begin(), v.end(), cmp);
        twoPointers(v, n);
    }
    return 0;
}
/* No Code - No Bug */