// bài toán mã đi tuần với đường đi ngắn nhất từ điểm a đến điểm b trên bàn cờ
#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<int, int>, int> piii;
#define max_n 1001
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

unordered_map<char, int> mp; 
void init(){
    mp['a'] = 1; mp['e'] = 5;
    mp['b'] = 2; mp['f'] = 6;
    mp['c'] = 3; mp['g'] = 7;
    mp['d'] = 4; mp['h'] = 8;
}
int visited[max_n][max_n];
void BFS(int u, int v, int s, int t){
    queue<piii> q;
    q.push({{u, v}, 0});
    visited[u][v] = 1;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first.first, y = it.first.second;
        int path = it.second;
        if(x == s && y == t){
            cout << path << endl;
            return;
        }
        for(int i = 0; i < 8; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi >= 1 && xi <= 8 && yi >= 1 && yi <= 8 && !visited[xi][yi]){
                q.push({{xi, yi}, path + 1});
                visited[xi][yi] = 1;
            }
        }
    }
}
void TestCase(){
    string s1, s2;
    cin >> s1 >> s2;
    memset(visited, 0, sizeof(visited));
    int u = mp[s1[0]], v = s1[1] - '0';
    int s = mp[s2[0]], t = s2[1] - '0';
    BFS(u, v, s, t);
}
int main(){
    Quick();
    init();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */