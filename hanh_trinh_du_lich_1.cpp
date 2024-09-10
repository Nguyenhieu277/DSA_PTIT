#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
int ans = INT_MAX;
int minProfit = INT_MAX;
int visited[max_n];
int a[max_n][max_n], x[max_n];
void init(){
    cin >> n;
    minProfit = INT_MAX;
    ans = INT_MAX;
    memset(a, 0, sizeof(a));
    memset(x, 0, sizeof(x));
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] != 0)
                minProfit = min(minProfit, a[i][j]);
        }
    }
}
void backTracking(int idx, int profit){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            x[idx] = i;
            visited[i] = 1;
            int before = x[idx - 1], after = x[idx];
            profit += a[before][after];
            if(idx == n){
                ans = min(ans, profit + a[1][x[idx]]);
            }
            else if(profit + (n - idx + 1) * minProfit < ans){
                backTracking(idx + 1, profit);
            }
            profit -= a[before][after];
            visited[i] = 0;
        }
    }
}
void TestCase(){
    init();
    x[1] = 1;
    visited[1] = 1;
    backTracking(2, 0);
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