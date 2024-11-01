#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void BFS(const vector<vector<int>>& grid, int n, int m, int u, int v){
    queue<piii> q;
    q.push({{u, v}, 0});
    vector<vector<int>> visited(n + 1, vector<int> (m + 1, 0));
    visited[u][v] = 1;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        int x = top.first.first, y = top.first.second;
        int step = top.second;
        if(x == n - 1 && y == m - 1){
            cout << step << endl;
            return;
        }
        int current = grid[x][y];
        if(x + current < n && !visited[x + current][y]){
            visited[x + current][y] = 1;
            q.push({{x + current, y}, step + 1});
        }
        if(y + current < m && !visited[x][y + current]){
            visited[x][y + current] = 1;
            q.push({{x, y + current}, step + 1});
        }
    }
    cout << -1 << endl;
}
void TestCase(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    BFS(grid, n, m, 0, 0);
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