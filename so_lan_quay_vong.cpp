#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


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
        int k = 0;
        for(int i = 1; i < n; i++){
            if(v[i] < v[k]){
                k = i;
            }
        }
        cout << k << endl;
    }
    return 0;
}
/* No Code - No Bug */