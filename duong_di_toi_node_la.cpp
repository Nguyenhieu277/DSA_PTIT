#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> List[max_n];
int visited[max_n];
int n;
vector<vector<int>> result;
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    result.clear();
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
    }
}
void DFS(int u, vector<int>& current){
    if(List[u].empty()){
        result.push_back(current);
    }
    visited[u] = 1;
    for(int v : List[u]){
        if(!visited[v]){
            current.push_back(v);
            DFS(v, current);
            current.pop_back();
        }
    }
}
void TestCase(){
    input();
    vector<int> current;
    current.push_back(1);
    DFS(1, current);
    sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b){
        return a.back() < b.back();
    });
    for(auto it : result){
        for(int i = 0; i < it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
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