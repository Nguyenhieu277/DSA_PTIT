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
    stack<int> st;
    vector<int> left(n + 1), right(n + 1);
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = 0;
        }
        else{
            left[i] = st.top() + 1;
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        if(st.empty()){
            right[i] = n - 1;
        }
        else{
            right[i] = st.top() - 1;
        }
        st.push(i);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(right[i] - left[i] + 1 >= nums[i]){
            res = max(res, nums[i]);
        }
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