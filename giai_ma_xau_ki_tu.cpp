#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void decodeString(const string& str){
    stack<char> st;
    for(char c : str){
        if(c == ']'){
            string tmp = "";
            while(!st.empty() && st.top() != '['){
                tmp = st.top() + tmp;
                st.pop(); 
            }
            st.pop();
            string res = "";
            while(!st.empty() && isdigit(st.top())){
                res = st.top() + res;
                st.pop();
            }
            int number = 1;
            if(!res.empty()){
                number = stoi(res);
            }
            string result = "";
            for(int i = 0; i < number; i++){
                result += tmp;
            }
            for(int i = 0; i < result.size(); i++){
                st.push(result[i]);
            }
        }
        else{
            st.push(c);
        }
    }
    string result = "";
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }
    cout << result << endl;
}
void TestCase(){
    string str;
    cin >> str;
    decodeString(str);
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