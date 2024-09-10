#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, s;
vector<int> List[max_n];
vector<int> path;
int visited[max_n];
void input(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    path.clear();
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        List[x].push_back(y);
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        path.push_back(v);
        for(int it : List[v]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}
void output(){
    for(int it : path){
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
        BFS(s);
        output();
    }
    return 0;
}
/* No Code - No Bug */