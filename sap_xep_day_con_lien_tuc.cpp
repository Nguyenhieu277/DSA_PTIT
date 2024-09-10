#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


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
        vector<int> sorted = v;
        sort(sorted.begin(), sorted.end());
        int left = 0;
        while(sorted[left] == v[left]){
            left++;
        }
        int right = n - 1;
        while(sorted[right] == v[right]){
            right--;
        }
        cout << left + 1 << " " << right + 1 << endl;
    }
    return 0;
}
/* No Code - No Bug */