#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool twoPointers(vector<ll> &v, int n, ll k){
    for(int i = 0; i < n - 2; i++){
        int j = i + 1;
        int h = n - 1;
        while(j < h){
            ll sum = v[i] + v[j] + v[h];
            if(sum == k){
                return true;
            }
            else if(sum < k){
                j++;
            }
            else h--;
        }
    }
    return false;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        if(twoPointers(v, n, k)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
/* No Code - No Bug */