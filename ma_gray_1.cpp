#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string toBinary(int n, int sz){
    string res = "";
    while(n > 0){
        res = (n % 2 == 0 ? "0" : "1") + res;
        n /= 2;
    }
    while(res.size() < sz){
        res.insert(0, "0");
    }
    return res;
}
void GrayCode(int n){
    vector<string> v;
    for(int i = 0; i < (1 << n); i++){
        int gray = i ^ (i >> 1);
        v.push_back(toBinary(gray, n));
    }
    for(string it : v){
        cout << it << " ";
    }
    cout << endl;
}
void TestCase(){
    int n;
    cin >> n;
    GrayCode(n);
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