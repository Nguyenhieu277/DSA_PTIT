#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;

    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        q.push(x);
    }
    ll ans = 0;
    while(q.size() > 1){
        ll tmp1 = q.top();
        q.pop();
        ll tmp2 = q.top();
        q.pop();
        ll total = (tmp1 + tmp2) % mod;
        ans = (ans + total) % mod;
        q.push(total);
    }
    cout << ans << endl;
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