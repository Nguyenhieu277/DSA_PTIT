#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void convert(string s){
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--){
        if(isalpha(s[i])){
            st.push(string(1, s[i]));
        }
        else{
            string tmp1 = st.top(); st.pop();
            string tmp2 = st.top(); st.pop();
            string str = tmp1 + tmp2 + s[i];
            st.push(str);
        }
    }
    cout << st.top() << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        convert(s);
    }
    return 0;
}
/* No Code - No Bug */