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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(c == 'q'){
            string tmp = str;
            reverse(tmp.begin() + l - 1, tmp.begin() + r);
            if(tmp == str){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else{
            str[l - 1] = r + '0';
        }
    }
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */