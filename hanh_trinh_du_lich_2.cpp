#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, k;
vector<pii> List[max_n];
vector<int> tourism;
void input(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    tourism.clear();
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        tourism.push_back(x);
    }
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        List[x].push_back({y, w});
        List[y].push_back({x, w});
    }
}
vector<int> Dijkstra(int s){
    vector<int> weight(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    weight[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        pii top = q.top();
        q.pop();

        int u = top.second, distance = top.first;
        if(distance > weight[u]) continue;
        for(pii it : List[u]){
            int v = it.first, w = it.second;
            if(weight[u] + w < weight[v]){
                weight[v] = weight[u] + w;
                q.push({weight[v], v});
            }
        }
    }
    return weight;
}
vector<vector<int>> dist_matrix;
vector<int> path;
ll minCost = LLONG_MAX;
int visited[max_n];
void backTracking(int idx, int currentCost){
    if(path.size() == k){
        currentCost += dist_matrix[path.back()][0];
        if(currentCost < minCost){
            minCost = currentCost;
        }
        return;
    }
    else if(path.size() < k){
        for(int i = 1; i < k; i++){
            if(!visited[i]){
                visited[i] = 1;
                path.push_back(i);
                backTracking(i, currentCost + dist_matrix[path[idx]][i]);
                path.pop_back();
                visited[i] = 0;
            }
        }
    }
}
void TestCase(){
    input();
    dist_matrix.resize(k, vector<int>(k, INT_MAX));
    path.clear();
    minCost = LLONG_MAX;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < k; i++){
        vector<int> dist = Dijkstra(tourism[i]);
        for(int j = 0; j < k; j++){
            dist_matrix[i][j] = dist[tourism[j]];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(dist_matrix[i][j] == INT_MAX){
                cout << -1 << endl;
                return;
            }
        }
    }
    path.push_back(0);
    visited[0] = 1;
    backTracking(0, 0);
    if(minCost == LLONG_MAX){
        cout << -1 << endl;
    }
    else{
        cout << minCost << endl;
    }
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */