#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<int> List[max_n];
int visited[max_n];
vector<int> v;
int level[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(level, 0, sizeof(level));
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
        level[x]++;
        level[y]++;
    }
}
void DFS(int u){
    v.push_back(u);
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
void TestCase(){
    input();
    for(int i = 1; i <= n; i++){
        v.clear();
        if(!visited[i]){
            DFS(i);
            for(int it : v){
                if(level[it] != v.size() - 1){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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