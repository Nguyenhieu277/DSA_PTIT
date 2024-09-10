#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, u;
vector<int> List[max_n];
vector<int> res;
int visited[max_n];
void input(){
    cin >> n >> m >> u;
    res.clear();
    for(int i = 1; i < max_n; i++){
        List[i].clear();
    }
    memset(visited, 0, sizeof(visited));
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
        int v = q.front();
        q.pop();
        res.push_back(v);
        for(int it : List[v]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}
void output(){
    for(int it : res){
        cout << it << " ";
    }
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        input();
        BFS(u);
        output();
    }
    return 0;
}
/* No Code - No Bug */