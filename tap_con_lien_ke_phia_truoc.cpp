#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
void generate(vector<int> &nums){
    int i = k;
    while(i > 0 && nums[i] == nums[i - 1] + 1){
        --i;
    }
    if(i > 0){
        nums[i]--;
    }
    for(int j = i + 1; j <= k; j++){
        nums[j] = n - k + j;
    }
    for(int j = 1; j <= k; j++){
        cout << nums[j] << " ";
    }
    cout << endl;
}
void TestCase(){
    cin >> n >> k;
    vector<int> nums(k + 1);
    for(int i = 1; i <= k; i++){
        cin >> nums[i];
    }
    generate(nums);
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