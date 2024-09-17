#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<int> List[max_n];
int color[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
    }
}
bool DFS(int u){
    color[u] = 1;
    for(int v : List[u]){
        if(color[v] == 0){
            if(DFS(v)){
                return true;
            }
        }
        else if(color[v] == 1){
            return true;
        }
    }
    color[u] = 2;
    return false;
}
void TestCase(){
    input();
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(DFS(i)){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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