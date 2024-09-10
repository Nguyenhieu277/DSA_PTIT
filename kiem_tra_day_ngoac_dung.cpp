#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool isValid(string s){
    stack<char> st;
    for(char it : s){
        if(it == '(' || it == '[' || it == '{'){
            st.push(it);
        }
        else{
            if(st.empty()){
                return false;
            }
            if((st.top() != '(' && it == ')') || (st.top() != '[' && it == ']') || (st.top() != '{' && it == '}')){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(isValid(s)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
/* No Code - No Bug */