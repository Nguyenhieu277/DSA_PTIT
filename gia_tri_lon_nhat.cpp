#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n;
    cin >> n;
    vector<ll> v;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
        if(x > 0) sum += x;
    }
    cout << sum * 2 << endl;
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */