#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int MooreVotingAlgorithm(vector<int> &v, int n){
    int ans = -1;
    int votes = 0;
    for(int i = 0; i < n; i++){
        if(votes == 0){
            ans = v[i];
            votes = 1;
        }
        if(ans == v[i]){
            votes++;
        }
        else votes--;
    }
    return ans;
}
bool isMajority(vector<int> &v, int n){
    int ans = MooreVotingAlgorithm(v, n);
    int cnt = 0;
    for(int it : v){
        if(ans == it){
            cnt++;
        }
    }
    return cnt > n / 2;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        int ans = MooreVotingAlgorithm(v, n);
        if(isMajority(v, n)){
            cout << ans << endl; 
        }
        else cout << "NO" << endl;
    }
    return 0;
}
/* No Code - No Bug */