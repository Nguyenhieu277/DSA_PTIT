#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int priority(char x){
    if(x == '^') return 3;
    else if(x == '*' || x == '/') return 2;
    else if(x == '+' || x == '-') return 1;
    else return -1;
}
void convert(string s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            res += char(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(char(s[i]));
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}
void TestCase(){
    string s;
    cin >> s;
    convert(s);
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