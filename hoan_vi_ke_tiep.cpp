#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<int> nums(max_n);
void init(){
    nums.clear();
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }
}
void generate(){
    int i = n - 1;
    while(i >= 1 && nums[i] >= nums[i + 1]){
        --i;
    }
    if(i >= 1){
        int j = n;
        while(nums[i] >= nums[j]) --j;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.begin() + n + 1);
    }
    else if(i == 0){
        reverse(nums.begin() + 1, nums.begin() + n + 1);
    }
    for(int i = 1; i <= n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        init();
        generate();
    }
    return 0;
}
/* No Code - No Bug */