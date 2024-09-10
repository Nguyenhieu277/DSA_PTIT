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
vector<int> degree(max_n);
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    degree.assign(max_n, 0);
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
        degree[x]++;
        degree[y]++; 
    }
}
void DFS(int u){
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
bool isConnected(){
    int start = -1;
    for(int i = 1; i <= n; i++){
        if(degree[i] > 0){
            start = degree[i];
            break;
        }
    }
    if(start == -1){
        return false;
    }
    DFS(start);
    for(int i = 1; i <= n; i++){
        if(!visited[i] && degree[i] > 0){
            return false;
        }
    }
    return true;
}
void checkEuler(){
    if(!isConnected()){
        cout << 0 << endl;
        return;
    }
    int oddCnt = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2 != 0){
            oddCnt++;
        }
    }
    if(oddCnt == 0){
        cout << 2 << endl;
    }
    else if(oddCnt == 2){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}
void TestCase(){
    input();
    checkEuler();
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