#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, a[max_n][max_n];
void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
}
void backTracking(int i, int j, int &cnt){
    if(i == n && j == m){
        cnt++;
        return;
    }
    if(i + 1 <= n){
        backTracking(i + 1, j, cnt);
    }
    if(j + 1 <= m){
        backTracking(i, j + 1, cnt);
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init();
        int cnt = 0;
        backTracking(1, 1, cnt);
        cout << cnt << endl;
    }
    return 0;
}
/* No Code - No Bug */