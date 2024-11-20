#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(vector<int>& nums, int n){
    vector<int> span(n + 1, 1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[i] >= nums[st.top()]){
            st.pop();
        }
        if(st.empty()){
            span[i] = i + 1;
        }
        else span[i] = i - st.top();
        st.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << span[i] << " ";
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
    solve(nums, n);
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