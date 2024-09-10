#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k, flag = 0;
vector<int> nums(max_n);
void init(){
    flag = 0;
    nums.resize(n + 1);
    for(int i = 1; i <= n; i++){
        nums[i] = 0;
    }
}
void generate(){
    int i = n;
    while(i >= 1 && nums[i] == 1){
        nums[i] = 0;
        --i;
    }
    if(i == 0){
        flag = 1;
    }
    else{
        nums[i] = 1;
    }
}
bool check(vector<int> &nums, int n, int k){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += nums[i];
    }
    return sum == k;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        init();
        while(!flag){
            if(check(nums, n, k)){
                for(int i = 1; i <= n; i++){
                    cout << nums[i];
                }
                cout << endl;
            }
            generate();
        }
    }
    return 0;
}
/* No Code - No Bug */