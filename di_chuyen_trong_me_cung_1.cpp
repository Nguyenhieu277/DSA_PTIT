#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, a[max_n][max_n];
vector<string> result;
void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    result.clear();
}
void backTracking(int i, int j, string res){
    if(i == n && j == n){
        result.push_back(res);
        return;
    }
    if(i + 1 <= n && a[i + 1][j] == 1){
        res += 'D';
        backTracking(i + 1, j, res);
        res.pop_back();
    }
    if(j + 1 <= n && a[i][j + 1] == 1){
        res += 'R';
        backTracking(i, j + 1, res);
        res.pop_back();
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        init();
        if(a[1][1] == 0 || a[n][n] == 0){
            cout << -1 << endl;
            continue;
        }
        string res = "";
        backTracking(1, 1, res);
        if(result.empty()){
            cout << -1 << endl;
            continue;
        }
        else{
            sort(result.begin(), result.end());
            for(string it : result){
                cout << it << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */