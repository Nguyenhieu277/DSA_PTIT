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
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    vector<int> In(n + 1, 1), Dec(n + 1, 1);
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i - 1]){
            In[i] = In[i - 1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] > nums[i + 1]){
            Dec[i] = Dec[i + 1] + 1;
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, In[i] + Dec[i] - 1);
    }
    cout << res << endl;
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