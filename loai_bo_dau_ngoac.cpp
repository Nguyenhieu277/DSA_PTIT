#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int maxLength = 0;
map<string, bool> mp;    

bool isValid(string str){
    if(str.size() < 2){
        return false;
    }
    stack<char> st;
    for(char c : str){
        if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
void backTracking(int idx, string str){
    if(str.size() < maxLength) return;
    if(isValid(str)){
        if(str.size() > maxLength){
            maxLength = str.size();
            mp.clear();
        }
        mp[str] = true;
        return;
    }
    for(int i = idx; i < str.size(); i++){
        if(str[i] == '(' || str[i] == ')'){
            string tmp = str;
            tmp.erase(i, 1);
            backTracking(i, tmp);
        }
    }
}
void TestCase(){
    string str;
    cin >> str;
    mp.clear();
    maxLength = 0;
    backTracking(0, str);
    if(mp.empty()){
        cout << -1 << endl;
    }
    else{
        for(auto it : mp){
            if(it.second == true){
                cout << it.first << " ";
            }
        }
        cout << endl;
    }
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