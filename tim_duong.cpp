#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, int> pii;
const int mod = 1000000007;
#define max_n 1001
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
char a[max_n][max_n];
char dir[] = {'D', 'L', 'R', 'U'};
struct path{
    int x, y, direction, turns;
};
void BFS(int x, int y, char c, int s, int t){
    queue<path> q;
    q.push({x, y, c, 0});
    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int u = top.x, v = top.y;
        int directions = top.direction;
        int turn = top.turns;
        if(u == s && v == t){
            cout << "YES" << endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            int ui = u + dx[i];
            int vi = v + dy[i];
            if(ui >= 1 && ui <= n && vi >= 1 && vi <= m && a[ui][vi] != '*'){
                if(directions != dir[i] && turn <= 3){
                    q.push({ui, vi, dir[i], turn + 1});
                }
                else if(directions == dir[i] && turn <= 3){
                    q.push({ui, vi, dir[i], turn});
                }
            }
        }
    }
    cout << "NO" << endl;
}
void TestCase(){
    cin >> n >> m;
    int x, y, s, t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                x = i;
                y = j;
            }
            else if(a[i][j] == 'T'){
                s = i;
                t = j;
            }
        }
    }
    BFS(x, y, 'H', s, t);
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