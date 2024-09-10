#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(string s){
    map<int, int> mp;
    for(char it : s){
        mp[it - 'a']++;
    }
    int tmp = -1;
    for(auto it : mp){
        tmp = max(tmp, it.second);
    }
    if(tmp > (s.size() + 1) / 2){
        cout << -1 << endl;
    }
    else cout << 1 << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
/* No Code - No Bug */