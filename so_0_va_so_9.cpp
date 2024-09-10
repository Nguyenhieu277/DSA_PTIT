#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void findElement(int n){
    queue<string> q;
    q.push("9");
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(stoll(s) % n == 0){
            cout << s << endl;
            return;
        }
        q.push(s + "0");
        q.push(s + "9");
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        findElement(n);
    }
    return 0;
}
/* No Code - No Bug */