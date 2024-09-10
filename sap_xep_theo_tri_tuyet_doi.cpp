#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int x;
bool cmp(int a, int b){
    int num1 = abs(x - a);
    int num2 = abs(x - b);
    return num1 < num2;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> x;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        stable_sort(v.begin(), v.end(), cmp);
        for(int it : v){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */