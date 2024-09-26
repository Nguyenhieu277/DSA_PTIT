#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, s;
vector<int> nums;
int minValue = INT_MAX;
void backTracking(int idx, int sum, vector<int>& current){
    if(current.size() >= minValue) return;
    if(sum == s){
        minValue = min(minValue, (int)current.size());
        return;
    }
    else if(sum > s || idx > n) return;
    else{
        for(int i = idx; i < n; i++){
            current.push_back(nums[i]);
            backTracking(i + 1, sum + nums[i], current);
            current.pop_back();
        }
    }
}
void TestCase(){
    nums.clear();
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    minValue = INT_MAX;
    vector<int> current;
    backTracking(0, 0, current);
    if(minValue == INT_MAX) cout << -1 << endl;
    else cout << minValue << endl;
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