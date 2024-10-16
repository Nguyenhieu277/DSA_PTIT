#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, s, t, u, v;
vector<vector<char>> matrix(max_n, vector<char>(max_n));
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cin >> s >> t >> u >> v;
}
int visited[max_n][max_n];
void BFS(int s, int t, int u, int v){
    queue<pair<pair<int, int>, int>> q;
    q.push({{s, t}, 0});
    visited[s][t] = 1;
    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int x = top.first.first, y = top.first.second, distance = top.second;
        if(x == u && y == v){
            cout << distance << endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            int xi = x, yi = y;
            while(true){
                xi += dx[i];
                yi += dy[i];
                if(xi >= 0 && xi < n && yi >= 0 && yi < n && !visited[xi][yi] && matrix[xi][yi] == '.'){
                    visited[xi][yi] = 1;
                    q.push({{xi, yi}, distance + 1});
                }
                else break;
            }
        }
    }
}
void TestCase(){
    input();
    memset(visited, 0, sizeof(visited));
    BFS(s, t, u, v);
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