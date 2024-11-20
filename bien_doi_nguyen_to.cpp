#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int prime[max_n];
void sieve(){
    for(int i = 2; i <= max_n; i++){
        prime[i] = 1;
    }
    for(int i = 2; i <= sqrt(max_n); i++){
        if(prime[i]){
            for(int j = i * i; j <= max_n; j += i){
                prime[j] = 0;
            }
        }
    }
}
void solve(int s, int t){
    queue<pair<int, int>> q;
    vector<int> visited(max_n, 0);
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int number = top.first;
        int step = top.second;
        if(number == t){
            cout << step << endl;
            return;
        }
        string str = to_string(number);
        for(int i = 0; i < str.size(); i++){
            string tmp = str;
            char start;
            if(i == 0) start = '1';
            else start = '0';
            for(char j = start; j <= '9'; j++){
                tmp[i] = j;
                int num = stoi(tmp);
                if(!visited[num] && prime[num]){
                    visited[num] = 1;
                    q.push({num, step + 1});
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