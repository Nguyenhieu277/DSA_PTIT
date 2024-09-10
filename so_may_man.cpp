#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n;
    cin >> n;
    int flag = 0;
    for(int i = n / 7; i >= 0; i--){
        int remainder = n - 7 * i;
        if(remainder % 4 == 0){
            flag = 1;
            int j = remainder / 4; 
            for(int x = 0; x < j; x++) cout << 4;
            for(int y = 0; y < i; y++) cout << 7;
            break;
        }
    }
    if(!flag) cout << -1;
    cout << endl;
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