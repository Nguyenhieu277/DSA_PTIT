#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(vector<int> &v, int n){
    vector<int> pos(n + 1, 0);
    for(int i = 0; i < n; i++){
        pos[v[i]] = i;
    }
    int cnt = 1;
    int maxIncrease = 1;
    for(int i = 2; i <= n; i++){
        if(pos[i] > pos[i - 1]){
            cnt++;
        }
        else{
            maxIncrease = max(maxIncrease, cnt);
            cnt = 1;
        }
    }
    maxIncrease = max(maxIncrease, cnt);
    cout << n - maxIncrease << endl;
}
int main(){
    Quick();    
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    solve(v, n);
    return 0;
}
/* No Code - No Bug */