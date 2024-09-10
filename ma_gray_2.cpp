#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    string s;
    cin >> s;
    string gray = "";
    gray += s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] == gray[i - 1]){
            gray += "0";
        }
        else gray += "1";
    }
    cout << gray << endl;
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