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
vector<int> parent(max_n);
int visited[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
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
                parent[v] = x;
            }
        }
    }
}
void output(int s, int t){
    BFS(s);
    if(!visited[t]){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    parent.assign(max_n, -1);
    memset(visited, 0, sizeof(visited));
}
void Query(){
    int query;
    cin >> query;
    while(query--){
        int x, y;
        cin >> x >> y;
        output(x, y);
    }
}
void TestCase(){
    input();
    Query();
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