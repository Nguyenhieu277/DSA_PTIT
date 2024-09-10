#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            q.push(x);
        }
        ll total = 0;
        while(q.size() > 1){
            int sum1 = q.top();
            q.pop();
            int sum2 = q.top();
            q.pop();
            total += sum1 + sum2;
            q.push(sum1 + sum2);
        }
        cout << total << endl;
    }
    return 0;
}
/* No Code - No Bug */