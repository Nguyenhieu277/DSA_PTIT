#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int KtoDecimal(string a, int k){
    int res = 0;
    for(int i = 0; i < a.size(); i++){
        res = res * k + a[i] - '0';
    }
    return res;
}
string DecimaltoK(int a, int k){
    string res = "";
    while(a != 0){
        res.push_back((a % k) + '0');
        a /= k;
    }
    reverse(res.begin(), res.end());
    return res; 
}
void TestCase(){
    int k; 
    string a, b;
    cin >> k >> a >> b;
    int num1 = KtoDecimal(a, k);
    int num2 = KtoDecimal(b, k);
    int res = num1 + num2;
    string ans = DecimaltoK(res, k);
    cout << ans << endl;
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