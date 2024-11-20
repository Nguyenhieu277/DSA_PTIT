#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void KadaneAlgorithm(vector<int>& nums, int n){
    int maxAns = INT_MIN;
    int currentAns = nums[0];
    for(int i = 1; i < n; i++){
        currentAns = max(nums[i], currentAns + nums[i]);
        if(maxAns < currentAns){
            maxAns = currentAns;
        }
    }
    cout << maxAns << endl;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    KadaneAlgorithm(nums, n);
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