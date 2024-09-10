#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k, cnt = 0;
vector<int> nums;
vector<int> curr;
vector<vector<int>> res;
void input(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
}
void backTrack(int idx, int sum){
    if(sum == k){
        res.push_back(curr);
        return;
    }
    if(sum > k || idx >= n){
        return;
    }
    backTrack(idx + 1, sum);
    curr.push_back(nums[idx]);
    backTrack(idx + 1, sum + nums[idx]);
    curr.pop_back();
}
int main(){
    Quick();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    backTrack(0, 0);
    for(auto it : res){
        for(int i = 0; i < it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
    cout << res.size() << endl;
    return 0;
}
/* No Code - No Bug */