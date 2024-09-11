#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll convertToDecimal(string s){
    ll res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res * 2 + s[i] - '0';
    }
    return res;
}
void solve(string s1, string s2){
    ll num1 = convertToDecimal(s1);
    ll num2 = convertToDecimal(s2);
    cout << num1 * num2 << endl; 
}
void TestCase(){
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
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