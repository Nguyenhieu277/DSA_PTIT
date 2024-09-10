#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(vector<int> &v, int n){
    vector<int> ins(n + 1, 1), dec(n + 1, 1);
    for(int i = 1; i < n; i++){
        if(v[i] > v[i - 1]){
            ins[i] = ins[i - 1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--){
        if(v[i] > v[i + 1]){
            dec[i] = dec[i + 1] + 1;
        }
    }
    int res = 1;
    for(int i = 0; i < n; i++){
        res = max(res, ins[i] + dec[i] - 1);
    }
    cout << res << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        solve(v, n);
    }
    return 0;
}
/* No Code - No Bug */