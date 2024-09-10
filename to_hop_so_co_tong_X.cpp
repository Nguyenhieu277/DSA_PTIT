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
bool isIncreasing(vector<int> &v){
    for(int i = 1; i < v.size(); i++){
        if(v[i] < v[i - 1]){
            return false;
        }
    }
    return true;
}
void backTracking(int idx, vector<int> &v, int x, int sum){
    if(sum == x){
        if(isIncreasing(current)){
            res.push_back(current);
        }
        return; 
    }
    else if(sum > x) return;
    else{
        for(int i = idx; i < v.size(); i++){
            current.push_back(v[i]);
            backTracking(i, v, x, sum + v[i]);
            current.pop_back();
        }
    }
}
void TestCase(){
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    res.clear();
    current.clear();
    backTracking(0, v, x, 0);
    if(res.empty()){
        cout << -1 << endl;
    }
    else{
        cout << res.size() << " ";
        for(auto it : res){
            cout << "{";
            for(int i = 0; i < it.size(); i++){
                cout << it[i];
                if(i != it.size() - 1){
                    cout << " ";
                }
                else cout << "}";
            }
            cout << " ";
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