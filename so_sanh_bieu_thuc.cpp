#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string convert(string str){
    stack<char> st;
    for(char c : str){
        if(c == ')'){
            string tmp = "";
            while(!st.empty() && st.top() != '('){
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            if(st.size() && st.top() == '-'){
                for(int i = 0; i < tmp.size(); i++){
                    if(tmp[i] == '-'){
                        tmp[i] = '+';
                    }
                    else if(tmp[i] == '+'){
                        tmp[i] = '-';
                    }
                }
            }
            for(int i = 0; i < tmp.size(); i++){
                st.push(tmp[i]);
            }
        }
        else st.push(c);
    }
    string res = "";
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}
void TestCase(){
    string str1, str2;
    cin >> str1 >> str2;
    str1 = convert(str1);
    str2 = convert(str2);
    if(str1 == str2){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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