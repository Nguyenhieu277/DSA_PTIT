#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<string> names, curr;
int n, k;
vector<vector<string>> res;
void backTrack(int idx){
    if(curr.size() == k){
        res.push_back(curr);
        return;
    }
    else{
        for(int i = idx; i < n; i++){
            curr.push_back(names[i]);
            backTrack(i + 1);
            curr.pop_back();
        }
    }
}
int main(){
    Quick();
    cin >> n >> k;
    set<string> se;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        se.insert(x);
    }
    for(auto it : se){
        names.push_back(it);
    }
    n = names.size();
    backTrack(0);
    for(auto it : res){
        for(int i = 0; i < it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */