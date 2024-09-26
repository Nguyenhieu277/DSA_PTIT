#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool isOperator(string c){
    return c == "+" || c == "-" || c == "*" || c == "/";
}
int solve(int i, vector<string> &str){
    if(isOperator(str[i])){
        if(str[i] == "+") return solve(i * 2 + 1, str) + solve(i * 2 + 2, str);
        if(str[i] == "-") return solve(i * 2 + 1, str) - solve(i * 2 + 2, str);
        if(str[i] == "*") return solve(i * 2 + 1, str) * solve(i * 2 + 2, str);
        if(str[i] == "/") return solve(i * 2 + 1, str) / solve(i * 2 + 2, str);
    }
    return stoi(str[i]);
}
void TestCase(){
    int n;
    cin >> n;
    vector<string> str;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        str.push_back(s);
    }
    cout << solve(0, str) << endl;
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