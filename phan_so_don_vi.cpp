#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(ll p, ll q){
    vector<ll> res;
    while(p != 0){
        ll x = (q + p - 1) / p;
        res.push_back(x);
        p = (p * x) - q;
        q = x * q;
    }
    for(int i = 0; i < res.size(); i++){
        cout << "1/" << res[i];
        if(i != res.size() - 1){
            cout << " + ";
        }
        else cout << endl;
    }
}
void TestCase(){
    ll p, q;
    cin >> p >> q;
    solve(p, q);
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