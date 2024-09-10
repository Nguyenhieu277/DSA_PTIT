#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


int main(){
    Quick();
    string s;
    stack<int> st;
    while(cin >> s){
        if(s == "push"){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(s == "show"){
            if(st.empty()){
                cout << "empty" << endl;
            }
            else{
                vector<int> v;
                while(!st.empty()){
                    v.push_back(st.top());
                    st.pop();
                }
                for(int i = v.size() - 1; i >= 0; i--){
                    cout << v[i] << " ";
                    st.push(v[i]);
                }
                cout << endl;
            }
        }
        else if(s == "pop"){
            if(!st.empty()){
                st.pop();
            }
            else continue;
        }
    }
    return 0;
}
/* No Code - No Bug */