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
        queue<string> q;
        q.push("1");
        for(int i = 0; i < n; i++){
            string tmp1 = q.front();
            q.pop();
            cout << tmp1 << " ";
            string tmp2 = tmp1;
            tmp1 += "0";
            tmp2 += "1";
            q.push(tmp1);
            q.push(tmp2);
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */