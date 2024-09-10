#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, row[max_n], col[max_n], diag1[max_n], diag2[max_n];
void backTracking(int i, int &cnt){
    if(i == n){
        cnt++;
        return;
    }
    else{
        for(int j = 0; j < n; j++){
            if(!row[j] && !col[j] && !diag1[i - j + n] && !diag2[i + j - 1]){
                row[j] = col[j] = diag1[i - j + n] = diag2[i + j - 1] = 1;
                backTracking(i + 1, cnt);
                row[j] = col[j] = diag1[i - j + n] = diag2[i + j - 1] = 0;
            }
        }
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int cnt = 0;
        cin >> n;
        backTracking(0, cnt);
        cout << cnt << endl;
    }
    return 0;
}
/* No Code - No Bug */