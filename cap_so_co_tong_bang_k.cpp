#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void hashMap(vector<ll> &v, int n, int k){
    unordered_map<ll, int> mp;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(mp.find(k - v[i]) != mp.end()){
            cnt += mp[k - v[i]];
        }
        mp[v[i]]++;
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
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        hashMap(v, n, k);
    }
    return 0;
}
/* No Code - No Bug */