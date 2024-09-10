#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<int> v, curr;
vector<vector<int>> res;
void backTracking(int idx){
    if(curr.size() >= 2){
        res.push_back(curr);
    }
    for(int i = idx; i < n; i++){
        if(curr.empty() || v[i] > curr.back()){
            curr.push_back(v[i]);
            backTracking(i + 1);
            curr.pop_back();
        }
    }
}
int main(){
    Quick();
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    vector<string> result;
    backTracking(0);
    for(auto it : res){
        string tmp = "";
        for(int i = 0; i < it.size(); i++){
            tmp += to_string(it[i]);
            if(i != it.size() - 1){
                tmp += " ";
            }
        }
        result.push_back(tmp);
    }
    sort(result.begin(), result.end());
    for(string it : result){
        cout << it << endl;
    }
    return 0;
}
/* No Code - No Bug */