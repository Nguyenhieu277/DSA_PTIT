#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int binarySearch(vector<int> &v, int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] == x){
            return mid + 1;
        }
        if(v[left] <= v[mid]){
            if(x >= v[left] && x < v[mid]){
                right = mid - 1;
            }
            else left = mid + 1;
        }
        else{
            if(x > v[mid] && x <= v[right]){
                left = mid + 1;
            }
            else right = mid - 1;
        }
    }
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
        cout << binarySearch(v, n, x) << endl;
    }
    return 0;
}
/* No Code - No Bug */