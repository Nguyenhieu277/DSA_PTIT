#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<pii> List[max_n];
int taken[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(taken, 0, sizeof(taken));
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        List[x].push_back({y, w});
        List[y].push_back({x, w});
    }
}
void Prim(int s){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(auto it : List[s]){
        if(!taken[it.first]){
            q.push({it.second, it.first});
        }
    }
    int weight = 0;
    taken[s] = 1;
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        int w = top.first, u = top.second;
        if(!taken[u]){
            weight += w;
            taken[u] = 1;
            for(pii it : List[u]){
                if(!taken[it.first]){
                    q.push({it.second, it.first});
                }
            }
        }
    }
    cout << weight << endl;
}
void TestCase(){
    input();
    Prim(1);
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