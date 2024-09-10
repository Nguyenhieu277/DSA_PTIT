#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int prime[MAX];
void sieve(){
    for(int i = 2; i <= MAX; i++){
        prime[i] = 1;
    }
    for(int i = 2; i <= sqrt(MAX); i++){
        if(prime[i]){
            for(int j = i * i; j <= MAX; j += i){
                prime[j] = 0;
            }
        }
    }
}
void solve(int s, int t){
    queue<pair<int, int>> q;
    vector<int> visited(MAX, 0);
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int u = x.first, step = x.second;
        if(u == t){
            cout << step << endl;
            return;
        }
        string s = to_string(u);
        for(int i = 0; i < s.size(); i++){
            string tmp = s;
            char start;
            if(i == 0) start = '1';
            else start = '0';
            for(char j = start; j <= '9'; j++){
                tmp[i] = j;
                int num = stol(tmp);
                if(prime[num] && !visited[num]){
                    q.push({num, step + 1});
                    visited[num] = 1;
                }
            }
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
    sieve();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */