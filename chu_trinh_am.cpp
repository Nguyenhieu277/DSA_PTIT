#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Edge{
    int x, y, w;
};
int n, m;
vector<Edge> List;
vector<int> weight(max_n);
void input(){
    cin >> n >> m;
    List.clear();
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        List.push_back({x, y, w});
    }
}
bool BellmanFord(int s){
    fill(weight.begin(), weight.end(), INT_MAX);
    weight[s] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(Edge e : List){
            if(weight[e.x] < INT_MAX){
                weight[e.y] = min(weight[e.y], weight[e.x] + e.w);
            }
        }
    }
    int flag = 0;
    for(Edge e : List){
        if(weight[e.x] < INT_MAX){
            if(weight[e.y] > weight[e.x] + e.w){
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
void negativeCycle(){
    fill(weight.begin(), weight.end(), INT_MAX);
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(weight[i] == INT_MAX){
            if(BellmanFord(i)){
                flag = 1;
                break;
            }
        }
    }
    if(flag) cout << 1 << endl;
    else cout << 0 << endl;
}
void TestCase(){
    input();
    negativeCycle();
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