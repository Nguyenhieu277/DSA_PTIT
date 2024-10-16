#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, s;
vector<pii> List[max_n];
vector<int> weight(max_n);
void input(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    weight.assign(max_n, INT_MAX);
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        List[x].push_back({y, w});
        List[y].push_back({x, w});
    }
}
void Dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    weight[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        pii top = q.top();
        q.pop();
        int distance = top.first;
        int u = top.second;
        if(distance > weight[u]) continue;
        for(pii v : List[u]){
            if(weight[u] + v.second < weight[v.first]){
                weight[v.first] = weight[u] + v.second;
                q.push({weight[v.first], v.first});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << weight[i] << " ";
    }
    cout << endl;
}
void TestCase(){
    input();
    Dijkstra(s);
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