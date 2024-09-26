#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<int> nums;
int ans = 0;
void backTracking(int idx, int sum, int target, int cnt){
    if(cnt == k && idx == n){
        ans++;
        return;
    }
    else{
        for(int i = idx; i < n; i++){
            sum += nums[i];
            if(sum == target) backTracking(i + 1, 0, target, cnt + 1);
        }
    }
}
void TestCase(){
    cin >> n >> k;
    nums.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k != 0){
        cout << 0 << endl;
        return;
    }
    ans = 0;
    int target = sum / k;
    backTracking(0, 0, target, 0);
    cout << ans << endl;
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