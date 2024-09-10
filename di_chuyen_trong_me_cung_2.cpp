#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int a[9][9];
string res = "";
int n;
int visited[max_n][max_n];
vector<string> v;
void backTracking(int i, int j){
    if(i == n && j == n){
        v.push_back(res);
        return;
    }
    visited[i][j] = 1;
    if(i + 1 <= n && a[i + 1][j] == 1 && !visited[i + 1][j]){
        res += "D";
        backTracking(i + 1, j);
        res.pop_back();
    }
    if(j + 1 <= n && a[i][j + 1] == 1 && !visited[i][j + 1]){
        res += "R";
        backTracking(i, j + 1);
        res.pop_back();
    }
    if(j - 1 > 0 && a[i][j - 1] == 1 && !visited[i][j - 1]){
        res += "L";
        backTracking(i, j - 1);
        res.pop_back();
    }
    if(i - 1 > 0 && a[i - 1][j] == 1 && !visited[i - 1][j]){
        res += "U";
        backTracking(i - 1, j);
        res.pop_back();
    }
    visited[i][j] = 0;
}
void TestCase(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    res.clear();
    v.clear();
    backTracking(1, 1);
    if(v.empty()){
        cout << -1;
    }
    else{
        sort(v.begin(), v.end());
        for(string it : v){
            cout << it << " ";
        }
    }
    cout << endl;
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