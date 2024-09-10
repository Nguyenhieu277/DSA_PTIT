#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int a[9][9], row[max_n], col[max_n], diag1[max_n], diag2[max_n];
void input(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> a[i][j];
        }
    }
}
ll res = 0;
void backTracking(int i, ll curr){
    if(i == 8){
        res = max(curr, res);
        return;
    }
    else{
        for(int j = 0; j < 8; j++){
            if(!row[j] && !col[j] && !diag1[i - j + 8] && !diag2[i + j - 1]){
                row[j] = col[j] = diag1[i - j + 8] = diag2[i + j - 1] = 1;
                curr += a[i][j];
                backTracking(i + 1, curr);
                curr -= a[i][j];
                row[j] = col[j] = diag1[i - j + 8] = diag2[i + j - 1] = 0;
            }
        }
    }
}
void TestCase(){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));
    input();
    res = 0;
    ll curr = 0;
    backTracking(0, curr);
    cout << res << endl;
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