#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void backTracking(int i, int j, int n, string current, vector<vector<int>>& a, vector<string>& res, vector<vector<int>> &visited){
    if(i == n && j == n){
        res.push_back(current);
        return;
    }
    visited[i][j] = 1;
    if(i + 1 <= n && a[i + 1][j] == 1 && !visited[i + 1][j]){
        current += "D";
        backTracking(i + 1, j, n, current, a, res, visited);
        current.pop_back();
    }
    if(j - 1 >= 1 && a[i][j - 1] == 1 && !visited[i][j - 1]){
        current += "L";
        backTracking(i, j - 1, n, current, a, res, visited);
        current.pop_back();
    }
    if(j + 1 <= n && a[i][j + 1] == 1 && !visited[i][j + 1]){
        current += "R";
        backTracking(i, j + 1, n, current, a, res, visited);
        current.pop_back();
    }
    if(i - 1 >= 1 && a[i - 1][j] == 1 && !visited[i - 1][j]){
        current += "U";
        backTracking(i - 1, j, n, current, a, res, visited);
        current.pop_back();
    }
    visited[i][j] = 0;
}
void TestCase(){
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> visited(n + 1, vector<int> (n + 1, 0));
    string current = "";
    vector<string> res;
    backTracking(1, 1, n, current, a, res, visited);
    sort(res.begin(), res.end());
    if(res.empty()){
        cout << -1 << endl;
        return;
    }
    for(string it : res){
        cout << it << " ";
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