#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<string> res;
string current = "";
void backTracking(int idx, string s){
    if(idx <= s.size()){
        if(!current.empty()){
            res.push_back(current);
        }
    }
    for(int i = idx; i < s.size(); i++){
        current.push_back(s[i]);
        backTracking(i + 1, s);
        current.pop_back();
    }
}
void TestCase(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    res.clear();
    current.clear();
    backTracking(0, s);
    for(string it : res){
        cout << it << " ";
    }
    cout << endl;
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