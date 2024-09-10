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
void backTracking(vector<int> &v, int idx, int x, int sum){
    if(sum == x){
        res.push_back(current);
        return;
    }
    else if(sum > x) return;
    else{
        for(int i = idx; i < v.size(); i++){
            current.push_back(v[i]);
            backTracking(v, i, x, sum + v[i]);
            current.pop_back();
        }
    }
}
void TestCase(){
    int n, x;
    cin >> n >> x;
    res.clear();
    current.clear();
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    backTracking(v, 0, x, 0);
    if(res.empty()){
        cout << -1 << endl;
    }
    else{
        for(auto it : res){
            cout << "[";
            for(int i = 0; i < it.size(); i++){
                cout << it[i];
                if(i != it.size() - 1){
                    cout << " ";
                }
                else cout << "]";
            }
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