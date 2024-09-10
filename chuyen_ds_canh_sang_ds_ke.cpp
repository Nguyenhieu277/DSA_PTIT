#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, m;
vector<int> List[max_n];
void input(){
    cin >> n >> m;
    for(int i = 1; i < max_n; i++){
        List[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    for(int it = 1; it <= n; it++){
        sort(List[it].begin(), List[it].end());
    }
}
void output(){
    for(int it = 1; it <= n; it++){
        cout << it << ": ";
        for(int i : List[it]){
            cout << i << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        input();
        output();
    }
    return 0;
}
/* No Code - No Bug */