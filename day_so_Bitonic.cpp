#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    vector<int> Increase;
    vector<int> Decrease;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
        Decrease.push_back(x);
        Increase.push_back(x);
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i] && Increase[i] < Increase[j] + nums[i]){
                Increase[i] = Increase[j] + nums[i];
            }
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(nums[j] < nums[i] && Decrease[i] < Decrease[j] + nums[i]){
                Decrease[i] = Decrease[j] + nums[i];
            }
        }
    }
    int value = -1;
    for(int i = 0; i < n; i++){
        value = max(value, Increase[i] + Decrease[i] - nums[i]);
    }
    cout << value << endl;
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