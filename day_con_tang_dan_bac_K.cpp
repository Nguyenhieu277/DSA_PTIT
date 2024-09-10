#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<vector<int>> res;
vector<int> nums;
vector<int> curr;
bool isInCreasing(vector<int> &curr){
    for(int i = 1; i < curr.size(); i++){
        if(curr[i] <= curr[i - 1]){
            return false;
        }
    }
    return true;
}
void backTracking(int idx){
    if(curr.size() == k){
        if(isInCreasing(curr)){
            res.push_back(curr);
        }
        return;
    }
    else{
        for(int i = idx; i < n; i++){
            curr.push_back(nums[i]);
            backTracking(i + 1);
            curr.pop_back();
        }
    }
}
void TestCase(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    backTracking(0);
    cout << res.size() << endl;
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