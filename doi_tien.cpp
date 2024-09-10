#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int money[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for(int it : money){
            while(n >= it){
                cnt++;
                n -= it;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
/* No Code - No Bug */