#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<int> nums;
int cnt = 0, flag = 0;
void backTracking(int idx, int target, int sum){
    if(sum > target || flag == 1) return;
    if(sum == target){
        cnt++;
        if(cnt == k){
            flag = 1;
            return;
        } 
    }
    else if(sum < target){
        for(int i = idx; i < n; i++){
            sum += nums[i];
            backTracking(i + 1, target, sum);
            sum -= nums[i];
        }
    }
}
void TestCase(){
    cin >> n >> k;
    nums.clear();
    cnt = 0;
    flag = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    } 
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k != 0){
        cout << 0 << endl;
        return;
    }
    int target = sum / k;
    backTracking(0, target, 0);
    if(flag) cout << 1 << endl;
    else cout << 0 << endl;
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