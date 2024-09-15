#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int solve(vector<int> &v, int n){
    int left = 0, right = n / 2, cnt = n;
    while(right < n && left < n / 2){
        if(v[left] * 2 <= v[right]){
            cnt--;
            left++;
        }
        right++;
    }
    return cnt;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << solve(v, n) << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */