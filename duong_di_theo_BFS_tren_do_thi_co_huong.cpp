#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, u, v;
vector<int> List[max_n];
int visited[max_n];
vector<int> parent(max_n);
void input(){
    cin >> n >> m >> u >> v;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    parent.assign(max_n, -1);
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int it : List[x]){
            if(!visited[it]){
                q.push(it);
                parent[it] = x;
                visited[it] = 1;
            }
        }
    }
}
void output(int s, int t){
    BFS(s);
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
            cout << it << ' ';
        }
        cout << endl;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        input();
        output(u, v);
    }
    return 0;
}
/* No Code - No Bug */