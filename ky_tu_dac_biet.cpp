#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

char findCharacter(const string& str, ll k){
    ll length = str.size();
    if(k < length){
        return str[k];
    }

    while(2 * length <= k){
        length *= 2;
    }
    if(k < length){
        return findCharacter(str, k);
    }
    else{
        return findCharacter(str, k - length - 1);
    }
}
void TestCase(){
    string str;
    ll k;
    cin >> str >> k;
    cout << findCharacter(str, k - 1) << endl;
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