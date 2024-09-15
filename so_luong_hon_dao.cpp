#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int a[max_n][max_n];
int visited[max_n][max_n];
int n, m;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
}
void DFS(int x, int y){
    visited[x][y] = 1;
    for(int i = 0; i < 8; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi >= 1 && xi <= n && yi >= 1 && yi <= m && !visited[xi][yi] && a[xi][yi] == 1){
            DFS(xi, yi);
        }
    }
}
void TestCase(){
    input();
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1 && !visited[i][j]){
                ++cnt;
                DFS(i, j);
            }
        }
    }
    cout << cnt << endl;
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