#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int solve(string str){
    if(str.empty()) return 0;
    stack<int> st;
    st.push(-1);
    int maxLength = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(!st.empty()){
                maxLength = max(maxLength, i - st.top());
            }
            else st.push(i);
        }
    }
    return maxLength;
}
void TestCase(){
    string str;
    cin >> str;
    cout << solve(str) << endl;
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