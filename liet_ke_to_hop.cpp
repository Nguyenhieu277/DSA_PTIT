#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<int> nums;
vector<int> curr;
void backTracking(int idx){
    if(curr.size() == k){
        for(int i = 0; i < curr.size(); i++){
            cout << curr[i] << " ";
        }
        cout << endl;
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
int main(){
    Quick();
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    n = nums.size();
    backTracking(0);
    return 0;
}
/* No Code - No Bug */