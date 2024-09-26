#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
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
void DFS(int x){
    visited[x] = 1;
    for(int v : List[x]){
        if(!visited[v]){
            path.push_back({x, v});
            DFS(v);
        }
    }
}
void TestCase(){
    input();
    DFS(u); 
    if(path.size() == n - 1){
        for(int i = 0; i < path.size(); i++){
            cout << path[i].first << " " << path[i].second << endl;
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