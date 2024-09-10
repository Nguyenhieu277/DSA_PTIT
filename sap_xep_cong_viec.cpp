#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int maxAction(vector<int> &start, vector<int> &end, int n){
    int cnt = 1;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int curr = v[0].first;
    for(int i = 1; i < v.size(); i++){
        if(curr <= v[i].second){
            cnt++;
            curr = v[i].first;
        }
    }
    return cnt;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> start, end;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            start.push_back(x);
        }
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            end.push_back(x);
        }
        cout << maxAction(start, end, n) << endl; 
    }
    return 0;
}
/* No Code - No Bug */