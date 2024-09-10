#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void findMinNumber(int s, int n){
    if(s > 9 * n){
        cout << -1 << endl;
        return;
    }
    int num[n + 1] = {0};
    int tmp = s;
    --tmp;
    for(int i = n; i >= 2; i--){
        if(tmp > 9){
            num[i] = 9;
            tmp -= 9;
        }
        else{
            num[i] = tmp;
            tmp = 0;
        }
    }
    num[1] = (tmp + 1);
    for(int i = 1; i <= n; i++){
        cout << num[i];
    }
    cout << endl;
}
void TestCase(){
    int s, n;
    cin >> s >> n;
    findMinNumber(s, n);
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