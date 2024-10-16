#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool isIncreasing(vector<int>& nums, int n){
    for(int i = 1; i < n; i++){
        if(nums[i] <= nums[i - 1]){
            return false;
        }
    }
    return true;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    if(isIncreasing(nums, n)){
        cout << 1 << endl;
    }
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