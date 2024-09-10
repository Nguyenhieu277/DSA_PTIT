#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> List[max_n];
int visited[max_n];
int disc[max_n], low[max_n];
int n, m, timer = 0;
vector<pii> bridge;
void input(){
    cin >> n >> m;
    bridge.clear();
    timer = 0;
    memset(visited, 0, sizeof(visited));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    for(int i = 1; i < max_n; i++){
        List[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
void DFS(int u, int par){
    visited[u] = 1;
    disc[u] = low[u] = ++timer;
    for(int v : List[u]){
        if(v == par) continue;
        if(!visited[v]){
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(disc[u] < low[v]){
                bridge.push_back({min(u, v), max(u, v)});
            }
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    }
}
void output(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i, -1);
        }
    }
    sort(bridge.begin(), bridge.end());
    for(pii it : bridge){
        cout << it.first << " " << it.second << " ";
    }
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        input();
        output();
    }
    return 0;
}
/* No Code - No Bug */