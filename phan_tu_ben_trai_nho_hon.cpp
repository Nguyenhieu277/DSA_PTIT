#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void findNextGreaterThenSmaller(vector<int>& nums, int n){
    vector<int> Greater(n + 1, -1);
    vector<int> Smaller(n + 1, -1);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        if(!st.empty()){
            Greater[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i = 0; i < n; i++){
        if(Greater[i] != -1){
            for(int j = Greater[i] + 1; j < n; j++){
                if(nums[j] < nums[Greater[i]]){
                    Smaller[i] = nums[j];
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << Smaller[i] << " ";
    }
    cout << endl;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    findNextGreaterThenSmaller(nums, n);
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