#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<int> v;
vector<int> current;
set<vector<int>> res;
void backTracking(int idx){
    if(current.size() == k){
        res.insert(current);
        return;
    }
    else{
        for(int i = idx; i < n; i++){
            current.push_back(v[i]);
            backTracking(i + 1);
            current.pop_back();
        }
    }
}
void TestCase(){
    cin >> n >> k;
    v.clear();
    res.clear();
    current.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    backTracking(0);
    for(auto it : res){
        for(int i = 0; i < it.size(); i++){
            cout << it[i] << " ";
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