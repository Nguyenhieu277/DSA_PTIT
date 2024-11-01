#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


vector<pair<int, int>> List[max_n];
vector<int> tourism;
int n, m, k;
void init(){
    cin >> n >> m >> k;
    tourism.clear();
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    for (int i = 0; i < k; i++) {
        int tourist_node;
        cin >> tourist_node;
        tourism.push_back(tourist_node);
    }

    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        List[x].push_back({y, w});
        List[y].push_back({x, w});
    }
}
vector<int> Dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> weight(n + 1, INT_MAX);
    q.push({0, s});
    weight[s] = 0;
    while(!q.empty()){
        pii top = q.top();
        q.pop();

        int distance = top.first;
        int u = top.second;
        if(distance > weight[u]) continue;
        for(auto x : List[u]){
            int v = x.first, dis = x.second;
            if(weight[u] + dis < weight[v]){
                weight[v] = weight[u] + dis;
                q.push({weight[v], v});
            }
        }
    }
    return weight;
}
int TSP(vector<vector<int>>& dist_matrix) {
    int n = dist_matrix.size();
    int k = tourism.size();
    vector<vector<int>> dp(k, vector<int>(1 << k, INT_MAX));
    
    for(int i = 0; i < k; i++) {
        dp[i][1 << i] = 0;
    }
    
    for(int currentMask = 0; currentMask < (1 << k); currentMask++) {
        if(__builtin_popcount(currentMask) == 1) {
            continue;
        } else {
            for(int i = 0; i < k; i++) {
                if(currentMask & (1 << i)) {
                    int prevMask = currentMask - (1 << i);
                    for(int j = 0; j < k; j++) {
                        if(prevMask & (1 << j)) {
                            dp[i][currentMask] = min(dp[i][currentMask], dp[j][prevMask] + dist_matrix[i][j]);
                        }
                    }
                }
            }
        }
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < k; i++) {
        ans = min(ans, dp[i][(1 << k) - 1]);
    }
    
    return ans;
}
void TestCase(){
    init();
    vector<vector<int>> dist_matrix(k + 1, vector<int> (k + 1, INT_MAX));
    for(int i = 0; i < k; i++){
        vector<int> dist = Dijkstra(tourism[i]);
        for(int j = 0; j < k; j++){
            dist_matrix[i][j] = dist[tourism[j]];
        }
    }
    int result = TSP(dist_matrix);
    cout << result << "\n";
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