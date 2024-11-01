#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 200001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> List[max_n];
vector<ll> countChild(max_n, 1);
vector<ll> nutrition(max_n, 1);

ll DFS(int u){
    ll cnt = 1;
    for(int v : List[u]){
        cnt += DFS(v);
    }
    countChild[u] = cnt;
    return cnt;
}
ll DFS2(ll u){
    ll sum = 1;
    for(int v : List[u]){
        sum += DFS2(v) + countChild[v];
    }
    nutrition[u] = sum;
    return sum;
}
void TestCase(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        List[x].push_back(i);
    }
    DFS(1);
    DFS2(1);
    for(int i = 1; i <= n; i++){
        cout << nutrition[i] << " ";
    }
    cout << endl;
}
int main(){
    Quick();
    TestCase();
}
/* No Code - No Bug */