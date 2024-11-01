#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Edge{
    int x, y, w;
};
int n, m;
vector<pii> MST;
vector<Edge> List;
int parent[max_n], sz[max_n];
void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    MST.clear();
}
void input(){
    cin >> n >> m;
    List.clear();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        List.push_back({u, v, w});
    } 
} 
int Find(int u){
    if(parent[u] == u){
        return u;
    }
    else return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v){
        return false;
    }
    if(sz[u] < sz[v]){
        swap(u, v);
    }
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}
void Kruskal(){
    int total = 0;
    sort(List.begin(), List.end(), [](const Edge& a, const Edge& b) -> bool{
        return a.w < b.w;
    });
    for(Edge e : List){
        if(MST.size() == n - 1) break;
        if(Union(e.x, e.y)){
            total += e.w;
            MST.push_back({e.x, e.y});
        }
    }
    if(MST.size() < n - 1){
        return;
    }
    else{
        cout << total << endl;
    }
}
void TestCase(){
    input();
    init();
    Kruskal();
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