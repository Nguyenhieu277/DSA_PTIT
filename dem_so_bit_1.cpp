#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll countBit1(ll n, ll l, ll r, ll start, ll end){
    ll cnt = 0;
    if(n == 0) return 0;

    if(r < start || l > end) return 0;
    ll mid = (start + end) / 2;
    if(mid >= l && mid <= r){
        cnt += n % 2;
    }
    cnt += countBit1(n / 2, l, r, start, mid - 1);
    cnt += countBit1(n / 2, l, r, mid + 1, end);
    return cnt;
}
void TestCase(){    
    ll n, l, r;
    cin >> n >> l >> r;
    ll tmp = n;
    ll length = 1;
    while(tmp > 1){
        tmp /= 2;
        length = 2 * length + 1;
    }
    cout << countBit1(n, l, r, 1, length) << endl;
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