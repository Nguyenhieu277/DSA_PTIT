#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 100001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(int s, int t){
    queue<pair<int, int>> q;
    vector<int> visited(max_n, 0);
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int current = x.first, step = x.second;
        if(current == t){
            cout << step << endl;
            return;
        }
        if(current - 1 >= 0 && !visited[current - 1]){
            q.push({current - 1, step + 1});
            visited[current - 1] = 1;
        }
        if(current * 2 < 10000 && !visited[current * 2]){
            q.push({current * 2, step + 1});
            visited[current * 2] = 1;
        }
    }
}
void TestCase(){
    int s, t;
    cin >> s >> t;
    solve(s, t);
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