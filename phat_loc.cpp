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
        nums[i] = 6;
    }
}
void generate(){
    int i = n;
    while(i >= 1 && nums[i] == 8){
        nums[i] = 6;
        --i;
    }
    if(i == 0){
        flag = 1;
    }
    else{
        nums[i] = 8;
    }
}
bool check(vector<int> &nums, int n){
    if(n < 6) return false;
    for(int i = 1; i <= n - 1; i++){
        if(nums[i] == 8 && nums[i + 1] == 8){
            return false;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(nums[i] == 6){
            cnt++;
        }
        else{
            if(cnt > 3){
                return false;
            }
            else cnt = 0;
        }
    }
    if(cnt > 3) return false;
    return (nums[1] == 8 && nums[n] == 6);
}
int main(){
    Quick();
    cin >> n;
    init();
    while(!flag){
        if(check(nums, n)){
        for(int i = 1; i <= n; i++){
                cout << nums[i];
            }
            cout << endl;
        }
        generate();
    }
    return 0;
}
/* No Code - No Bug */