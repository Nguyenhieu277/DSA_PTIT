#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int prime[MAX];
void sieve(){
    prime[0] = prime[1] = 1;
    for(int i = 2; i <= sqrt(MAX); i++){
        if(!prime[i]){
            for(int j = i * i; j <= MAX; j += i){
                prime[j] = 1;
            }
        }
    }
}
int main(){
    Quick();
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int flag = 0;
        for(int i = 2; i <= n / 2; i++){
            if(!prime[i] && !prime[n - i]){
                cout << i << " " << n - i << endl;
                flag = 1;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}
/* No Code - No Bug */