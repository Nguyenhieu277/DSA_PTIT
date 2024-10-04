#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool Compare(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first && a.second < b.second;
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
void LIS(vector<pair<int, int>>& nums, const int& n){
    vector<pair<int, int>> dp;
    for(int i = 0; i < n; i++){
        if(dp.empty() || Compare(dp.back(), nums[i])){
            dp.push_back(nums[i]);
        } 
        else{
            auto idx = lower_bound(dp.begin(), dp.end(), nums[i], cmp);
            *idx = nums[i];
        }
    }
    cout << dp.size() << endl;
}
void TestCase(){
    int n;
    cin >> n;
    vector<pair<int, int>> nums;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        nums.push_back({x, y});
    }
    LIS(nums, n);
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */