#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll fibo[max_n];
void init(){
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i = 3; i < 93; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}
char findCharacter(ll n, ll k){
    if(n == 1){
        return 'A';
    }
    if(n == 2){
        return 'B';
    }
    if(k <= fibo[n - 2]){
        return findCharacter(n - 2, k);
    }
    else return findCharacter(n - 1, k - fibo[n - 2]);
}
int main(){
    Quick();
    int t;
    cin >> t;
    init();
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << findCharacter(n, k) << endl;
    }
    return 0;
}
/* No Code - No Bug */