#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string solve(vector<int> &v, int n){
    vector<int> sortedV = v;
    sort(sortedV.begin(), sortedV.end());
    for(int i = 0; i < n; i++){
        if(v[i] != sortedV[i] && v[i] != sortedV[n - i - 1]){
            return "No";
        }
    }
    return "Yes";
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
        cout << solve(v, n) << endl;
    }
    return 0;
}
/* No Code - No Bug */