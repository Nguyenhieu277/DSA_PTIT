#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Dish{
    int n, s, m;
};
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        Dish a;
        cin >> a.n >> a.s >> a.m;
        int target = a.s * a.m;
        int totalDay;
        if(a.s >= 7) totalDay = (a.s / 7) * 6 + min(6, a.s % 7);
        else totalDay = min(6, a.s);
        if(totalDay * a.n < target){
            cout << -1 << endl;
        } 
        else{
            int res = ceil((double)target / a.n);
            cout << res << endl;
        }
    }
    return 0;
}
/* No Code - No Bug */