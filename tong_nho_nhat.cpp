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
        sort(v.begin(), v.end());
        ll num1 = 0, num2 = 0;
        for(int i = 0; i < v.size(); i += 2){
            num1 = num1 * 10 + v[i];
        }
        for(int i = 1; i < v.size(); i += 2){
            num2 = num2 * 10 + v[i]; 
        }
        cout << num1 + num2 << endl;
    }
    return 0;
}
/* No Code - No Bug */