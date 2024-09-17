#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<int> List[max_n];
int visited[max_n];
vector<int> parent(max_n);
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    parent.resize(max_n);
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
bool DFS(int u){
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            parent[v] = u;
            if(DFS(v)){
                return true;
            }
        }
        else if(v != parent[u]){
            return true;
        }
    }
    return false;
}
void TestCase(){
    input();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(DFS(i)){
                cout << "YES" << endl;
                return;
            }
        }
    }    
    cout << "NO" << endl;
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