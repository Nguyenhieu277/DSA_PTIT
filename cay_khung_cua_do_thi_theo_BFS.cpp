#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, u;
vector<int> List[max_n];
int visited[max_n];
vector<pair<int, int>> path;
void input(){
    cin >> n >> m >> u;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    path.clear();
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
void BFS(int u){
    visited[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int v : List[x]){
            if(!visited[v]){
                path.push_back({x, v});
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
void TestCase(){
    input();
    BFS(u);
    if(path.size() == n - 1){
        for(auto it : path){
            cout << it.first << " " << it.second << endl;
        }
    }
    else cout << -1 << endl;
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