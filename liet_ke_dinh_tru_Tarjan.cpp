#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<int> List[max_n];
int visited[max_n];
vector<int> disc(max_n), low(max_n);
int AP[max_n];
int timer = 0;
void input(){
    cin >> n >> m;
    timer = 0;
    memset(visited, 0, sizeof(visited));
    disc.resize(max_n, 0);
    low.resize(max_n, 0);
    memset(AP, 0, sizeof(AP));
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
void Tarjan(int u, int parent){
    int child = 0;
    low[u] = disc[u] = ++timer;
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            Tarjan(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            if(parent != -1 && low[v] >= disc[u]){
                AP[u] = 1;
            }
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    } 
    if(parent == -1 && child > 1) AP[u] = 1;
}
void TestCase(){
    input();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            Tarjan(i, -1);
        }
    }
    for(int i = 1; i <= n; i++){
        if(AP[i]){
            cout << i << " ";
        }
    }
    cout << endl;
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