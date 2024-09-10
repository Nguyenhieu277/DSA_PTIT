#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void convert(int n){
    queue<pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int u = it.first, step = it.second;
        if(u == 1){
            cout << step << endl;
            return;
        }
        if(u % 3 == 0) q.push({u / 3, step + 1});
        if(u % 2 == 0) q.push({u / 2, step + 1});
        if(u - 1 >= 1) q.push({u - 1, step + 1});
    }
}
void TestCase(){
    int n;
    cin >> n;
    convert(n);
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