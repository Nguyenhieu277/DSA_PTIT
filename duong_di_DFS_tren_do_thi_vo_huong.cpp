#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, s, t;
vector<int> parent(max_n);
vector<int> List[max_n];
int visited[max_n];
void input(){
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    parent.resize(max_n);
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    } 
    memset(visited, 0, sizeof(visited));
}
void DFS(int u){
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v);
            parent[v] = u;
        }
    }
}
void print(int s, int t){
    if(!visited[t]){
        cout << -1 << endl;
        return;
    }
    else{
        vector<int> path;
        while(t != s){
            path.push_back(t);
            t = parent[t];
        } 
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int it : path){
            cout << it << " ";
        }
        cout << endl;
    }
}
void TestCase(){
    input();
    DFS(s);
    print(s, t);
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