#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Edge{
    int x, y;
    double w;
};
int n;
vector<Edge> List;
int parent[max_n], sz[max_n];
void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u){
    if(u == parent[u]){
        return parent[u];
    }
    else return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
void Kruskal(){
    double total = 0;
    sort(List.begin(), List.end(), [](const Edge& a, const Edge& b) -> bool{
        return a.w < b.w;
    });
    int cnt = 0;
    for(auto it : List){
        if(Union(it.x, it.y)){
            total += it.w;
            cnt++;
        }
    }
    if(cnt < n - 1){
        return;
    }
    else{
        cout << fixed << setprecision(6) << total << endl;
    }
}
void TestCase(){
    List.clear();
    cin >> n;
    init();
    vector<pair<double, double>> points;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            double x1 = points[i].first, y1 = points[i].second;
            double x2 = points[j].first, y2 = points[j].second;
            double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            List.push_back({i + 1, j + 1, distance});
        }
    }
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