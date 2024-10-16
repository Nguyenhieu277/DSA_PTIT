#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Zone{
    int x, y, u, v;

    bool operator < (const Zone& other) const {
        return tie(x, y, u, v) < tie(other.x, other.y, other.u, other.v);
    };
};
int n, k, m;
set<Zone> BanZone;
vector<pair<int, int>> SheepPositon;
int component[max_n][max_n];
int visited[max_n][max_n];
bool hasFence(int x, int y, int u, int v){
    return BanZone.count({x, y, u, v}) || BanZone.count({u, v, x, y});
}
void DFS(int x, int y, int id){
    visited[x][y] = 1;
    component[x][y] = id;
    for(int i = 0; i < 4; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi >= 1 && xi <= n && yi >= 1 && yi <= n && !visited[xi][yi] && !hasFence(x, y, xi, yi)){
            DFS(xi, yi, id);
        }
    }
}
void input(){
    cin >> n >> k >> m;
    for(int i = 0; i < m; i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        BanZone.insert({x, y, u, v});
    }
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        SheepPositon.push_back({x, y});
    }
}
void TestCase(){
    input();
    int id = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!visited[i][j]){
                DFS(i, j, ++id);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k; j++){
            auto [x1, y1] = SheepPositon[i];
            auto [x2, y2] = SheepPositon[j];
            if(component[x1][y1] != component[x2][y2]){
                cnt++;
            } 
        }
    }
    cout << cnt << endl;
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */