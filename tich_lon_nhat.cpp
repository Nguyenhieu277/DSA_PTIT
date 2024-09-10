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
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll maxProduct2 = max(v[1] * v[0], v[n - 1] * v[n - 2]);
    ll maxProduct3 = max(v[1] * v[0] * v[n - 1], v[n - 1] * v[n - 2] * v[n - 3]);
    ll maxProduct = max(maxProduct2, maxProduct3);
    cout << maxProduct << endl;
    return 0;
}
/* No Code - No Bug */