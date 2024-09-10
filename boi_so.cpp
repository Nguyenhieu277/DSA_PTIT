#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int remainder(string s, int divisor){
    ll res = 0;
    for(char c : s){
        res = (res * 10 + (c - '0')) % divisor;
    }
    return res;
}
void findElement(int n){
    queue<string> q;
    q.push("9");
    while(!q.empty()){
        string top = q.front();
        q.pop();
        if(remainder(top, n) == 0){
            cout << top << endl;
            return;
        }
        q.push(top + "0");
        q.push(top + "9");
    }
}
void TestCase(){
    int n;
    cin >> n;
    findElement(n); 
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