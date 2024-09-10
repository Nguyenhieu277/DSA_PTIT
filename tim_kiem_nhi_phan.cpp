#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void binarySearch(vector<int> &v, int n, int k){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] == k){
            cout << mid + 1 << endl;
            return;
        }
        else if(v[mid] < k){
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << "NO" << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        binarySearch(v, n, k);
    }
    return 0;
}
/* No Code - No Bug */