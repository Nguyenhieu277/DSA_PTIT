#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string special(8, '0');
vector<string> res;
void solve(){
    int day = stoi(special.substr(0, 2));
    int month = stoi(special.substr(2, 2));
    int year = stoi(special.substr(4));
    if(day > 0 && day <= 31 && month > 0 && month <= 12 && year >= 2000){
        string tmp = special;
        tmp.insert(2, 1, '/');
        tmp.insert(5, 1, '/');
        res.push_back(tmp);
    }
}
void backTracking(int idx){
    for(int i = 0; i <= 1; ++i){
        if(i == 0) special[idx] = '0';
        else special[idx] = '2';
        if(idx == 7) solve();
        else{
            backTracking(idx + 1);
        }
    }
}
int main(){
    Quick();
    backTracking(0);
    sort(res.begin(), res.end());
    for(string it : res){
        cout << it << endl;
    }
    return 0;
}
/* No Code - No Bug */