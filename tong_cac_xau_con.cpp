#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    string str;
    cin >> str;
    ll res = 0;
    for(int i = 0; i < str.size(); i++){
        string tmp = "";
        for(int j = i; j < str.size(); j++){
            tmp += str[j];
            res += stoll(tmp);  
        }
    }
    cout << res << endl;
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