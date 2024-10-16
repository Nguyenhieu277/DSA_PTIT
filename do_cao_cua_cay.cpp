#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> List[max_n];
int result = INT_MIN;
int n;
int visited[max_n];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    } 
    memset(visited, 0, sizeof(visited));
    result = INT_MIN;
    for(int i = 1; i < n; i++){
        int x, y; 
        cin >> x >> y;
        List[x].push_back(y);
    }
}
void DFS(int u, int depth){
    result = max(result, depth);
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v, depth + 1);
        }
    }
}
void TestCase(){
    input();
    DFS(1, 0);
    cout << result << endl; 
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