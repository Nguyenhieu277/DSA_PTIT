#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(string s){
    ll res = 0;
    int cnt = 0;
    for(char c : s){
        if(c == '['){
            cnt++;
        }
        else{
            cnt--;
            res += (cnt < 0 ? -cnt : 0);
        }
    }
    cout << res << endl;
}
void TestCase(){
    string s;
    cin >> s;
    solve(s);
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