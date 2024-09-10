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
vector<int> inDegree(max_n), outDegree(max_n);
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        List[i].clear(); 
    }
    inDegree.assign(max_n, 0);
    outDegree.assign(max_n, 0);
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        inDegree[x]++;
        outDegree[y]++;
    }
}
bool isEuler(){
    for(int i = 1; i <= n; i++){
        if(inDegree[i] != outDegree[i]){
            return false;
        }
    }
    return true;
}
void TestCase(){
    input();
    if(isEuler()){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
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