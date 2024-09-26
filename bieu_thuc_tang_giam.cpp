#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(string str){
    stack<int> st;
    int cnt = 1;
    st.push(1);
    for(char c : str){
        if(c == 'D'){
            cnt++;
            st.push(cnt);
        }
        else{
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            cnt++;
            st.push(cnt);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}
void TestCase(){
    string str;
    cin >> str;
    solve(str);
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