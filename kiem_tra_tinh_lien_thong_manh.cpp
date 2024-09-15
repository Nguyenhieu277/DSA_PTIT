#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<int> List[max_n], reList[max_n];
int visited[max_n];
stack<int> st;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
        reList[i].clear();
    }   
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        reList[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
}
void DFS(int u){
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
    st.push(u);
}
void DFS2(int u){
    visited[u] = 1;
    for(int v : reList[u]){
        if(!visited[v]){
            DFS2(v);
        }
    }
}
void TestCase(){
    input();
    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i);
    }
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    while(!st.empty()){
        int v = st.top();
        st.pop();
        if(!visited[v]){
            cnt++;
            DFS2(v);
        }
    }
    if(cnt == 1){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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