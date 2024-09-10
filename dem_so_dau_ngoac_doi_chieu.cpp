#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(string s){
    stack<char> st;
    if(s.size() % 2 != 0){
        return;
    }
    for(char it : s){
        if(it == '('){
            st.push(it);
        }
        else{
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else st.push(it);
        }
    }
    int open = 0, close = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(top == '('){
            open++;
        }
        else close++;
    }
    cout << (open + 1) / 2 + (close + 1) / 2 << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
/* No Code - No Bug */