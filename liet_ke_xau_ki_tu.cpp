#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string s = "";
string curr = "";
char x;
int n;
void init(){
    cin >> x >> n;
    for(char i = 'A'; i <= x; i++){
        s += i;
    }
}
void backTracking(int idx){
    if(curr.size() == n){
        cout << curr << endl;
        return;
    }
    else{
        for(int i = idx; i < s.size(); i++){
            curr.push_back(s[i]);
            backTracking(i);
            curr.pop_back();
        }
    }
}
int main(){
    Quick();
    init();
    backTracking(0);
    return 0;
}
/* No Code - No Bug */