#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> nums(max_n);
int n, k;
void init(){
    nums.clear();
    for(int i = 1; i <= k; i++){
        cin >> nums[i];
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
    else if(i == 0){
        for(int j = 1; j <= k; j++){
            nums[j] = j;
        }
    }
    for(int i = 1; i <= k; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        init();
        generate();
    }
    return 0;
}
/* No Code - No Bug */