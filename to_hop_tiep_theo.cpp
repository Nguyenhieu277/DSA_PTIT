#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<int> nums(max_n);
set<int> se;
void init(){
    nums.resize(k + 1);
    se.clear();
    for(int i = 1; i <= k; i++){
        cin >> nums[i];
        se.insert(nums[i]);
    }
}
void generate(){
    int i = k;
    while(i >= 1 && nums[i] == n - k + i){
        --i;
    }
    if(i >= 1){
        nums[i]++;
        for(int j = i + 1; j <= k; j++){
            nums[j] = nums[j - 1] + 1;
        }
    }
}
int solve(set<int> &se, vector<int> &nums, int k){
    int cnt = 0;
    for(int i = 1; i <= k; i++){
        if(se.find(nums[i]) == se.end()){
            cnt++;
        }
    }
    if(cnt == 0) return k;
    else return cnt;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        init();
        generate();
        cout << solve(se, nums, k) << endl;
    }
    return 0;
}
/* No Code - No Bug */