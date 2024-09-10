#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> merge(vector<int> &v1, vector<int> &v2){
    int i = 0, j = 0;
    vector<int> res;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            res.push_back(v1[i]);
            i++;
        }
        else{
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()){
        res.push_back(v1[i++]);
    }
    while(j < v2.size()){
        res.push_back(v2[j++]);
    }
    return res;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v1, v2;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v1.push_back(x);
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            v2.push_back(x);
        }
        vector<int> res = merge(v1, v2);
        cout << res[k - 1] << endl;
    }
    return 0;
}
/* No Code - No Bug */