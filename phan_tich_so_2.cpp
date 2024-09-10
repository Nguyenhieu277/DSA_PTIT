#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<vector<int>> res;
vector<int> current;
void backTracking(int idx, int sum){
    if(sum == n){
        if(!current.empty()){
            res.push_back(current);
        }
        return;
    }
    else if(sum > n) return;
    else{
        for(int i = idx; i >= 1; i--){
            current.push_back(i);
            backTracking(i, sum + i);
            current.pop_back();
        }
    }
}
void TestCase(){
    cin >> n;
    res.clear();
    current.clear();
    backTracking(n, 0);
    cout << res.size() << endl;
    for(auto it : res){
        cout << "(";
        for(int i = 0; i < it.size(); i++){
            cout << it[i];
            if(i != it.size() - 1){
                cout << " ";
            }
            else cout << ")";
        }
        cout << " ";
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