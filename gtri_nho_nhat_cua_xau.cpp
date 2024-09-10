#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(string s, int k){
    unordered_map<char, int> mp;
    for(char c : s){
        mp[c]++;
    }
    vector<int> frequency;
    for(auto it : mp){
        if(it.second > 0){
            frequency.push_back(it.second);
        }
    }
    for(int i = 0; i < k; i++){
        sort(frequency.begin(), frequency.end());
        frequency[frequency.size() - 1]--;
    }
    ll ans = 0;
    for(int it : frequency){
        ans += it * it;
    }
    cout << ans << endl;
}
void TestCase(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    solve(s, k);
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