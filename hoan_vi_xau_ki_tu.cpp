#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string s;
string curr = "";
vector<string> res;
vector<bool> visited(max_n);
void init(){
    res.clear();
    cin >> s;
}
void backTracking(int idx){
    if(curr.size() == s.size()){
        res.push_back(curr);
        return;
    }
    else{
        for(int i = idx; i < s.size(); i++){
            if(!visited[i]){
                curr.push_back(s[i]);
                visited[i] = true;
                backTracking(idx);
                curr.pop_back();
                visited[i] = false;
            }
            
        }
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        init();
        backTracking(0);
        for(string it : res){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */