#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> LeftSpin(vector<int> &v){
    vector<int> res = v;
    res[0] = v[3];
    res[1] = v[0];
    res[3] = v[4];
    res[4] = v[1];
    return res;
}
vector<int> RightSpin(vector<int> &v){
    vector<int> res = v;
    res[1] = v[4];
    res[2] = v[1];
    res[4] = v[5];
    res[5] = v[2];
    return res;
}
void BFS(vector<int>& start, vector<int>& end){
    queue<pair<vector<int>, int>> q;
    q.push({start, 0});
    set<vector<int>> visited;
    visited.insert(start);
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        vector<int> tmp = top.first;
        int step = top.second;
        if(tmp == end){
            cout << step << endl;
            return;
        }
        vector<int> left = LeftSpin(tmp);
        if(visited.count(left) == 0){
            visited.insert(left);
            q.push({left, step + 1});
        }
        vector<int> right = RightSpin(tmp);
        if(visited.count(right) == 0){
            visited.insert(right);
            q.push({right, step + 1});
        }
    }
}
void TestCase(){
    vector<int> v1, v2;
    for(int i = 0; i < 6; i++){
        int x; cin >> x;
        v1.push_back(x);
    }
    for(int i = 0; i < 6; i++){
        int x; cin >> x;
        v2.push_back(x);
    }
    BFS(v1, v2);
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