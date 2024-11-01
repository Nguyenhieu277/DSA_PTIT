#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int mod = 1000000007;
#define max_n 35
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, 0, 0, -1, 1};
const int dz[] = {0, 0, -1, 1, 0, 0};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int A, B, C;
char matrix[max_n][max_n][max_n];
int visited[max_n][max_n][max_n];
int x, y, z, a, b, c;
void input(){
    cin >> A >> B >> C;
    for(int i = 1; i <= A; i++){
        for(int j = 1; j <= B; j++){
            for(int k = 1; k <= C; k++){
                cin >> matrix[i][j][k];
                if(matrix[i][j][k] == 'S'){
                    x = i; y = j; z = k;
                }
                else if(matrix[i][j][k] == 'E'){
                    a = i; b = j; c = k;
                }
            }
        }
    }
    memset(visited, 0, sizeof(visited));
}
void BFS(int x, int y, int z, int a, int b, int c){
    queue<pair<piii, int>> q;
    q.push({{{x, y}, z}, 0});
    visited[x][y][z] = 1;
    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int u = top.first.first.first, v = top.first.first.second;
        int t = top.first.second;
        int distance = top.second;
        if(u == a && v == b && t == c){
            cout << distance << endl;
            return;
        }
        for(int i = 0; i < 6; i++){
            int ui = u + dx[i];
            int vi = v + dy[i];
            int ti = t + dz[i];
            if(ui >= 1 && ui <= A && vi >= 1 && vi <= B && ti >= 1 && ti <= C && !visited[ui][vi][ti] && matrix[ui][vi][ti] != '#'){
                q.push({{{ui, vi}, ti}, distance + 1});
                visited[ui][vi][ti] = 1;
            }
        }
    }
    cout << -1 << endl;
}
void TestCase(){
    input();
    BFS(x, y, z, a, b, c);
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