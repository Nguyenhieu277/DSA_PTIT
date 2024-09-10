#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool isValid(string s){
    stack<int> st;
    for(char it : s){
        if(it == ')'){
            char top = st.top();
            st.pop();
            int flag = 0;
            while(!st.empty() && top != '('){
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    flag = 1;
                }
                top = st.top();
                st.pop();
            }
            if(!flag) return true;
        }
        else st.push(it);
    }
    return false;
}
int main(){
    Quick();
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        if(isValid(s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}
/* No Code - No Bug */