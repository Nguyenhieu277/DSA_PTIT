#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, u;
vector<int> List[max_n];
vector<int> v;
int visited[max_n];
void input(){
    cin >> n >> m >> u;
    v.clear();
    for(int i = 1; i < max_n; i++){
        List[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
}
void DFS(int u){
    visited[u] = 1;
    v.push_back(u);
    for(int it : List[u]){
        if(!visited[it]){
            DFS(it);
        }
    }
}
void output(){
    for(int it : v){
        cout << it << ' ';
    }
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        input();
        DFS(u);
        output();
    }
    return 0;
}
/* No Code - No Bug */