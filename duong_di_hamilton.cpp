#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
int flag = 0;
vector<int> List[max_n];
int visited[max_n];
void input(){
    cin >> n >> m;
    flag = 0;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
void DFS(int u, int cnt){
    if(cnt == n){
        flag = 1;
        return;
    } 
    if(flag) return;
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v, cnt + 1);
        }
    }
    visited[u] = 0;
}
void TestCase(){
    input();
    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        DFS(i, 1);
        if(flag){
            break;
        }
    }
    cout << ((flag == 1) ? 1 : 0) << endl;
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