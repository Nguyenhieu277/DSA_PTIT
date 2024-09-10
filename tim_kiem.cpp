#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool binarySearch(vector<int> &v, int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] == x){
            return true;
        }
        else if(v[mid] < x){
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return false;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        if(binarySearch(v, n, x)){
            cout << 1 << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
/* No Code - No Bug */