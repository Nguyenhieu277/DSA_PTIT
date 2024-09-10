#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void countBDN(ll n){
    queue<string> q;
    q.push("1");
    int cnt = 0;
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(stoll(s) <= n){
            cnt++;
            q.push(s + "0");
            q.push(s + "1");
        }
        else break;
    }
    cout << cnt << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        countBDN(n);
    }
    return 0;
}
/* No Code - No Bug */