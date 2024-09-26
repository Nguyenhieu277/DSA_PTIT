#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
set<int> List[max_n];
int visited[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].insert(y);
        List[y].insert(x);
    }
}
int cnt = 0;
void DFS(int u){
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            ++cnt;
            DFS(v);
        }
    }
}
void TestCase(){
    input();
    int ans = -1;
    for(int i = 1; i <= n; i++){
        cnt = 1;
        if(!visited[i]){
            DFS(i);
        }
        ans = max(ans, cnt);
    } 
    cout << ans << endl;
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