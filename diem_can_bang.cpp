#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void BalanceIndex(vector<int> &v, int n){
    int total = 0, leftSum = 0;
    total = accumulate(v.begin(), v.end(), 0);
    for(int i = 0; i < n; i++){
        if(leftSum == total - leftSum - v[i]){
            cout << i + 1 << endl;
            return;
        }
        leftSum += v[i];
    }
    cout << -1 << endl;
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
        BalanceIndex(v, n);
    }
    return 0;
}
/* No Code - No Bug */