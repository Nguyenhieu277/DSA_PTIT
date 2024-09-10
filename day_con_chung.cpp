#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> ThreePointers(vector<int> &v1, vector<int> &v2, vector<int> &v3){
    int i = 0, j = 0, k = 0;
    vector<int> res;
    while(i < v1.size() && j < v2.size() && k < v3.size()){
        if(v1[i] == v2[j] && v2[j] == v3[k]){
            res.push_back(v1[i]);
            i++; j++; k++;
        }
        else if(v1[i] < v2[j]){
            i++;
        }
        else if(v2[j] < v3[k]){
            j++;
        }
        else k++;
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
        vector<int> v1, v2, v3;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v1.push_back(x);
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            v2.push_back(x);
        }
        for(int i = 0; i < k; i++){
            int x; cin >> x;
            v3.push_back(x);
        }
        vector<int> res = ThreePointers(v1, v2, v3);
        if(res.empty()){
            cout << "NO" << endl;
        }
        else{
            for(int it : res){
                cout << it << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
/* No Code - No Bug */