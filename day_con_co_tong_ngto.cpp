#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<int> v;
vector<int> current;
set<vector<int>> res;
int prime[MAX];
void sieve(){
    for(int i = 2; i <= MAX; i++){
        prime[i] = 1;
    }
    for(int i = 2; i <= sqrt(MAX); i++){
        if(prime[i]){
            for(int j = i * i; j <= MAX; j += i){
                prime[j] = 0;
            }
        }
    }
}
void backTracking(int idx, int sum){
    if(prime[sum]){
        res.insert(current);
    }
    for(int i = idx; i < n; i++){
        current.push_back(v[i]);
        backTracking(i + 1, sum + v[i]);
        current.pop_back();
    }
}
void TestCase(){
    cin >> n;
    v.clear();
    res.clear();
    current.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    backTracking(0, 0);
    for(auto it : res){
        for(int i = 0; i < it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    sieve();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */