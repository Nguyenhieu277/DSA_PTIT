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
    nums.clear();
    res.clear();
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
    for(int i = idx; i < n; i++){
        curr.push_back(nums[i]);
        backTrack(i + 1, sum + nums[i]);
        curr.pop_back();
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        input();
        sort(nums.begin(), nums.end());
        backTrack(0, 0);
        if(res.empty()){
            cout << -1 << endl;
            continue;
        }
        else{
            for(auto it : res){
                cout << '[';
                for(int i = 0; i < it.size(); i++){
                    cout << it[i];
                    if(i != it.size() - 1){
                        cout << " ";
                    }
                    else cout << ']';
                }
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/* No Code - No Bug */