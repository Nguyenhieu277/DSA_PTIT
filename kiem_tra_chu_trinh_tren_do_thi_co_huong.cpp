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
int degree[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear();
    }
    memset(degree, 0, sizeof(degree));
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        degree[y]++;
    }
}
int cnt = 0;
void BFS(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cnt++;
        for(int v : List[x]){
            degree[v]--;
            if(degree[v] == 0){
                q.push(v);
            }
        }
    } 
}
void TestCase(){
    input();
    cnt = 0;
    BFS();
    if(cnt != n){
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