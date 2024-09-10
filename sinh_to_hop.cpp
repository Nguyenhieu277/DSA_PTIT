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
    nums.clear();
    flag = 0;
    for(int i = 1; i <= k; i++){
        nums[i] = i;  
    }
}
void generate(){
    int i = k;
    while(i >= 1 && nums[i] == n - k + i){
        --i;
    }
    if(i == 0){
        flag = 1;
    }
    else{
        nums[i]++;
        for(int j = i + 1; j <= k; j++){
            nums[j] = nums[j - 1] + 1;
        }
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        init();
        while(!flag){
            for(int i = 1; i <= k; i++){
                cout << nums[i];
            }
            cout << " ";
            generate();
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */