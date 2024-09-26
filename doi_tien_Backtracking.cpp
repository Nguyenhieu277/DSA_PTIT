#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int minVal = INT_MAX;
void backTracking(int n, int s, int idx, vector<int> &moneys, vector<int> &curr, int sum){
    if(curr.size() >= minVal) return;
    if(sum == s){
        minVal = min(minVal, (int)curr.size());
        return;
    }
    else if(sum > s) return;
    else{
        for(int i = idx; i < n; i++){
            curr.push_back(moneys[i]);
            backTracking(n, s, i + 1, moneys, curr, sum + moneys[i]);
            curr.pop_back();
        }
    }
}
void TestCase(){
    int n, s;
    cin >> n >> s;
    vector<int> moneys;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        moneys.push_back(x);
    }
    vector<int> curr;
    backTracking(n, s, 0, moneys, curr, 0);
    if(minVal == INT_MAX) cout << -1 << endl;
    else cout << minVal << endl;
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */