#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll BruteForce(vector<int> &v, int n){
    ll closestSum = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll sum = v[i] + v[j];
            if(abs(sum) < abs(closestSum)){
                closestSum = sum;
            }
        }
    }
    return closestSum;
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
        cout << BruteForce(v, n) << endl;
    }
    return 0;
}
/* No Code - No Bug */