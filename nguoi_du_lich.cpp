#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
int a[max_n][max_n];
int visited[max_n];
int x[max_n] = {0};
int minVal = INT_MAX;
int ans = INT_MAX;
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            minVal = min(minVal, a[i][j]);
        }
    }
}
void backTracking(int idx, int profit){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            x[idx] = i;
            visited[i] = 1;
            int before = x[idx - 1], now = x[idx];
            profit += a[before][now];
            if(idx == n){
                ans = min(ans, profit + a[1][x[idx]]);
            }
            else if(profit + (n - idx + 1) * minVal < ans){
                backTracking(idx + 1, profit);
            }
            profit -= a[before][now];
            visited[i] = 0;
        }
    }   
}
void TestCase(){
    input();
    x[1] = 1;
    visited[1] = 1;
    backTracking(2, 0);
    cout << ans << endl;
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */