#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool hasPytagoTriplet(vector<ll> &v, int n){
    for(int i = 0; i < n; i++){
        v[i] *= v[i];
    }
    sort(v.begin(), v.end());
    for(int i = n - 1; i >= 2; i--){
        int j = 0, k = i - 1;
        while(j < k){
            if(v[k] + v[j] == v[i]){
                return true;
            }
            else if(v[k] + v[j] < v[i]){
                j++;
            }
            else k--;
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
        cin >> n;
        vector<ll> v;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v.push_back(x);
        }
        if(hasPytagoTriplet(v, n)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
/* No Code - No Bug */