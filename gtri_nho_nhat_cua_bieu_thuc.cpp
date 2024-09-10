#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll solve(vector<int> &v1, vector<int> &v2){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    ll sum = 0;
    for(int i = 0; i < v1.size(); i++){
        sum += v1[i] * v2[i];
    }
    return sum;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> v1, v2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v1.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v2.push_back(x);
    }
    ll ans = min(solve(v1, v2), solve(v2, v1));
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