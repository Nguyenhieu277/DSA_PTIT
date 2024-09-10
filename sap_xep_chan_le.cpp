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
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    vector<int> odd, even;
    for(int i = 0; i < n; i += 2){
        even.push_back(v[i]);
    }
    for(int i = 1; i < n; i += 2){
        odd.push_back(v[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());
    vector<int> res(n);
    int oddIdx = 0, evenIdx = 0;
    for(int i = 0; i < n; i++){
        if((i) % 2 == 1){
            res[i] = odd[oddIdx++];
        }
        else res[i] = even[evenIdx++];
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
/* No Code - No Bug */