#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int n, m;
    cin >> n >> m;
    vector<int> v1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v1.push_back(x);
    }
    vector<int> v2;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        v2.push_back(x);
    }
    vector<int> res(n + m + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res[i + j] += v1[i] * v2[j];
        }
    }
    for(int i = 0; i < n + m - 1; i++){
        cout << res[i] << " ";
    }
    cout << endl;
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