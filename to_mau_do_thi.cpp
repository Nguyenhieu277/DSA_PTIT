#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m, e;
vector<int> List[max_n];
int color[max_n];
void input(){
    cin >> n >> m >> e;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
}
bool isSafe(int u, int e){
    for(int v : List[u]){
        if(color[v] == e){
            return false;
        }
    }
    return true;
}
bool graphColoring(int v, int n, int e){
    if(v == n + 1){
        return true;
    }
    for(int i = 1; i <= e; i++){
        if(isSafe(v, i)){
            color[v] = i;
            if(graphColoring(v + 1, n, e)){
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}
void TestCase(){
    input();
    if(graphColoring(1, n, e)){
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