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
        map<int, int> mp;
        for(int it : v){
            mp[it]++;
        }
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(mp[v[i]] > 1){
                cout << v[i] << endl;
                flag = 1;
                break;
            }
        }
        if(!flag) cout << "NO" << endl;
    }
    return 0;
}
/* No Code - No Bug */