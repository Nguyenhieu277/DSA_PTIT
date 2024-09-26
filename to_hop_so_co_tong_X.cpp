#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<int> nums;
vector<int> current;
vector<vector<int>> res;
void backTracking(int idx, int sum){
    if(sum == k){
        res.push_back(current);
        return;
    }
    else if(sum > k || idx > n) return;
    else{
        for(int i = idx; i < n; i++){
            if(current.empty() || (current.back() <= nums[i])){
                current.push_back(nums[i]);
                backTracking(idx, sum + nums[i]);
                current.pop_back();
            }
        }
    }
}
void TestCase(){
    cin >> n >> k;
    nums.clear();
    current.clear();
    res.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    backTracking(0, 0);
    if(res.empty()){
        cout << -1 << endl;
    }
    else{
        cout << res.size() << " ";
        for(auto it : res){
            cout << "{";
            for(int i = 0; i < it.size(); i++){
                cout << it[i];
                if(i != it.size() - 1){
                    cout << " ";
                }
                else cout << "}";
            }
            cout << " ";
        }
        cout << endl;
    }
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