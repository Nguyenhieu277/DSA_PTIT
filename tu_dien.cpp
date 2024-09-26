#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int k, m, n;
set<string> dic;
char a[max_n][max_n];
string current = "";
int visited[max_n][max_n];
vector<string> res;
void backTracking(int x, int y){
    current += a[x][y];
    visited[x][y] = 1;
    if(dic.find(current) != dic.end()){
        res.push_back(current);
    }
    for(int i = 0; i < 8; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi >= 1 && xi <= n && yi >= 1 && yi <= m && !visited[xi][yi]){
            backTracking(xi, yi);
        }
    }
    current.pop_back();
    visited[x][y] = 0;
}
void TestCase(){
    cin >> k >> n >> m;
    dic.clear();
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        dic.insert(s);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    current.clear();
    res.clear();
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            backTracking(i, j);
        }
    }
    if(res.empty()){
        cout << -1 << endl;
    }
    else{
        for(string it : res){
            cout << it << " ";
        }
        cout << endl;
    }
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