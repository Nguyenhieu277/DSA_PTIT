#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(vector<int> &v, int n){
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n / 2; i++){
        cout << sorted[n - i - 1] << " " << sorted[i];
        if(i != n - 1){
            cout << " ";
        }
    }
    cout << endl;
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