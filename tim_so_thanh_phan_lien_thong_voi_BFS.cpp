#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<vector<int>> List;
vector<int> visited;
void input(){
    cin >> n >> m;
    List.clear(); List.resize(n + 10);
    visited.clear(); visited.resize(n + 10, 0);
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int v : List[x]){
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}
void TestCase(){
    input();
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            BFS(i);
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