#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<vector<int>> res;
vector<int> current;
void backTracking(int sum, int n, int idx){
    if(sum == n){
        res.push_back(current);
        return;
    }
    else if(sum < n){
        for(int i = n; i >= idx; i--){
            current.push_back(i);
            backTracking(sum + i, n, i);
            current.pop_back();
        }
    }
}
void TestCase(){
    int n;
    cin >> n;
    current.clear();
    res.clear();
    backTracking(0, n, 1);
    for(int i = 0; i < (int)res.size(); i++){
        sort(res[i].begin(), res[i].end(), greater<int>());
    }
    sort(res.begin(), res.end(), greater<>());
    for(int i = 0; i < (int)res.size(); i++){
        cout << "(";
        for(int j = 0; j < (int)res[i].size(); j++){
            cout << res[i][j];
            if(j != (int)res[i].size() - 1){
                cout << " ";
            }
        }
        cout << ")" << " ";
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