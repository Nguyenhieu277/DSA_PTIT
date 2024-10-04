#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int k, n, m;
vector<int> position; // vi tri ban dau
vector<int> place(max_n); // noi hop mat
vector<int> List[max_n];
vector<int> visited(max_n);
void input(){
    cin >> k >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    visited.assign(max_n, 0);
    position.clear();
    place.assign(n + 1, 0);
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        position.push_back(x);
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
    }
}
void DFS(int u){
    visited[u] = 1;
    place[u]++;
    for(int v : List[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
} 
void TestCase(){
    input();
    for(int it : position){ // duyet tu vi tri ban dau den noi hop mat
        visited.assign(max_n, 0);
        DFS(it);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){ // tim noi hop mat
        if(place[i] == k){
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */