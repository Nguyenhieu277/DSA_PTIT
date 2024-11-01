#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
int maxLength = INT_MIN;
int visited[max_n][max_n];
vector<int> List[max_n];
void input(){
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++){
        List[i].clear();
    }
    maxLength = INT_MIN;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
void DFS(int u, int length){
    if(length > maxLength){
        maxLength = length;
    }
    for(int v : List[u]){
        if(!visited[u][v]){
            visited[u][v] = visited[v][u] = 1;
            DFS(v, length + 1);
            visited[u][v] = visited[v][u] = 0;
        }
    }
}
void TestCase(){
    input();
    for(int i = 0; i < n; i++){
        DFS(i, 0);
    }
    cout << maxLength << endl;
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