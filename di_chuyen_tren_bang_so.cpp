#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int mod = 1000000007;
#define max_n 501
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
int matrix[max_n][max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
}
void Dijkstra(int x, int y){
    priority_queue<piii, vector<piii>, greater<piii>> q;
    q.push({matrix[x][y], {x, y}});
    vector<vector<int>> weight(n + 1, vector<int> (m + 1, INT_MAX));
    weight[x][y] = matrix[x][y];
    while(!q.empty()){
        piii top = q.top();
        q.pop();
        int distance = top.first;
        pii x = top.second;
        int u = x.first, v = x.second;
        if(distance > weight[u][v]){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int ui = u + dx[i];
            int vi = v + dy[i];
            if(ui >= 1 && ui <= n && vi >= 1 && vi <= m){
                if(weight[u][v] + matrix[ui][vi] < weight[ui][vi]){
                    weight[ui][vi] = weight[u][v] + matrix[ui][vi];
                    q.push({weight[ui][vi], {ui, vi}});
                }
            }
        }
    }
    cout << weight[n][m] << endl;
}
void TestCase(){
    input();
    Dijkstra(1, 1);
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