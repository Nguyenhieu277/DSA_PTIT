#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
#define max_n 101
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<vector<char>> matrix(max_n, vector<char>(max_n, 0));
bool visited[max_n][max_n];
void DFS(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 8; i++){
        int xi = x + dx[i];
        int yi = y + dy[i];
        if(xi >= 1 && xi <= n && yi >= 1 && yi <= m && !visited[xi][yi] && matrix[xi][yi] == 'W'){
            DFS(xi, yi);
        }
    }
}
void TestCase(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(matrix[i][j] == 'W' && !visited[i][j]){
                cnt++;
                DFS(i, j);
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