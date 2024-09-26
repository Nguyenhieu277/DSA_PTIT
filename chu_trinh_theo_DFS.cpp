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
vector<int> parent(max_n);
vector<int> path, res;
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    path.clear();
    res.clear();
    parent.resize(max_n, -1);
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    path.push_back(1);
    for(int i = 1; i <= n; i++){
        sort(List[i].begin(), List[i].end());
    }
}
int flag = 0;
void DFS(int u){
    if(flag) return;
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            parent[v] = u;
            path.push_back(v);
            DFS(v);
        }
        else if(v != parent[u] && v == 1){
            res.clear();
            int curr = u;
            while(curr != 1){
                res.push_back(curr);
                curr = parent[curr];
            }
            res.push_back(1);
            flag = 1;
            return;
        }
    }
} 
void print(){
    DFS(1);
    if(!flag){
        cout << "NO" << endl;
    }
    else{
        reverse(res.begin(), res.end());
        res.push_back(1);
        for(int it : res){
            cout << it << " ";
        }
        cout << endl;
    }
}
void TestCase(){
    input();
    flag = 0;
    print();
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