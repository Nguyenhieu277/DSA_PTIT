#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<int> tmp;
int visited[max_n];
vector<vector<int>> res;
void backTracking(int idx){
    if(tmp.size() == n){
        res.push_back(tmp);
        return;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(!visited[i] && (tmp.empty() || abs(tmp.back() - i) != 1)){
                visited[i] = 1;
                tmp.push_back(i);
                backTracking(idx + 1);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        res.clear();
        backTracking(1);
        sort(res.begin(), res.end());
        for(auto it : res){
            for(int i = 0; i < it.size(); i++){
                cout << it[i];
            }
            cout << endl;
        }
    }
    return 0;
}
/* No Code - No Bug */