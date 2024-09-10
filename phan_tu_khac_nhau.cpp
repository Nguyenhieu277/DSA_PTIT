#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int findElement(vector<ll> &v1, vector<ll> &v2){
    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] == v2[j]){
            i++;
            j++;
        }
        else{
            return i;
        }
    }
    if(i < v1.size()){
        return i;
    }
    if(j < v2.size()){
        return j;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v1, v2;
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            v1.push_back(x);
        }
        for(int i = 0; i < n - 1; i++){
            ll x; cin >> x;
            v2.push_back(x);
        }
        int ans = findElement(v1, v2);
        cout << ans + 1 << endl;
    }
    return 0;
}
/* No Code - No Bug */