#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void commonOfThreeArrays(vector<ll> &v1, vector<ll> &v2, vector<ll> &v3){
    int i = 0, j = 0, k = 0;
    vector<ll> res;
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
    if(res.empty()){
        cout << -1 << endl;
    }
    else{
        for(ll it : res){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> v1, v2, v3;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v1.push_back(x);
        }
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v2.push_back(x);
        }
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v3.push_back(x);
        }
        commonOfThreeArrays(v1, v2, v3);
    }
    return 0;
}
/* No Code - No Bug */