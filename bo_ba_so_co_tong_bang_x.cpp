#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void twoPointers(vector<ll> &v, int n, ll x){
    ll cnt = 0;
    for(int i = 0; i < n - 2; i++){
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            ll sum = v[i] + v[j] + v[k];
            if(sum < x){
                cnt += (k - j);
                j++; 
            }
            else k--;
        }
    }
    cout << cnt << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        twoPointers(v, n, x);
    }
    return 0;
}
/* No Code - No Bug */