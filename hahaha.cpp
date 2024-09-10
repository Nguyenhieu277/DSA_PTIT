#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, flag = 0;
vector<char> nums(max_n);
void init(){
    nums.resize(n + 1);
    flag = 0;
    for(int i = 1; i <= n; i++){
        nums[i] = 'A';
    }
}
void generate(){
    int i = n;
    while(i >= 1 && nums[i] == 'H'){
        nums[i] = 'A';
        --i;
    }
    if(i == 0){
        flag = 1;
    }
    else{
        nums[i] = 'H';
    }
}
bool check(vector<char> &nums, int n){
    int alert = 0;
    for(int i = 1; i <= n - 1; i++){
        if(nums[i] == 'H' && nums[i + 1] == 'H'){
            alert = 1;
            break;
        }
    }
    return (nums[1] == 'H' && nums[n] == 'A') && !alert;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
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
    }
    return 0;
}
/* No Code - No Bug */