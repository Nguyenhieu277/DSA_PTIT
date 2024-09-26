#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int parent[max_n], sz[max_n];
vector<pair<int, int>> path;
int n, m;
int Find(int u){
    if(u == parent[u]){
        return u;
    }
    else return parent[u] = Find(parent[u]);
}
void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u != v){
        if(sz[u] < sz[v]){
            swap(u, v);
        }
        parent[v] = u;
        sz[u]++;
    }
    
}
void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 0;
    }
    path.clear();
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        path.push_back({x, y});
    }
}
bool hasCycle(){
    for(int i = 0; i < path.size(); i++){
        int x = Find(path[i].first);
        int y = Find(path[i].second);

        if(x == y){
            return true;
        }
        Union(x, y);
    }
    return false;
}
void TestCase(){
    init();
    if(hasCycle()){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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