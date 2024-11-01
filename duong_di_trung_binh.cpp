#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<vector<int>> dist(max_n, vector<int> (max_n, INT_MAX));
int n, m;
void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(dist[i].begin(), dist[i].end(), INT_MAX);
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        dist[x][y] = 1;
    }
}
void FloydWarshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] < INT_MAX && dist[k][j] < INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
void result(){
    FloydWarshall();
    int total = 0;
    int countPairs = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j && dist[i][j] < INT_MAX){
                total += dist[i][j];
                countPairs++;
            }
        }
    }
    cout << fixed << setprecision(2) << (double)total / countPairs << endl;
}
void TestCase(){
    init();
    result(); 
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