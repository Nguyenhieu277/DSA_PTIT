#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<int> current;
vector<vector<int>> res;
int visited[max_n];
void backTracking(int idx){
    if(current.size() == n){
        res.push_back(current);
        return;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(!visited[i] && (current.empty() || abs(current.back() - i) != 1)){
                current.push_back(i);
                visited[i] = 1;
                backTracking(idx + 1);
                visited[i] = 0;
                current.pop_back();
            }
        }
    }
}
void TestCase(){
    cin >> n;
    current.clear();
    res.clear();
    memset(visited, 0, sizeof(visited));
    backTracking(1);
    for(auto it : res){
        for(int i = 0; i < it.size(); i++){
            cout << it[i];
        }
        cout << endl;
    }
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