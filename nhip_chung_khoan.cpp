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
    vector<int> nums, span(n + 1, 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        span[i] = (st.empty() ? i + 1 : (i - st.top()));

        st.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << span[i] << " ";
    }
    cout << endl;
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