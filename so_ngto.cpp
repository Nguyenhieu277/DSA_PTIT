#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 10001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, p, s;
int prime[max_n];
vector<int> primes(max_n);
vector<int> current;
vector<vector<int>> res;
void sieve(){
    for(int i = 2; i <= max_n; i++){
        prime[i] = 1;
    }
    for(int i = 2; i <= sqrt(max_n); i++){
        if(prime[i]){
            for(int j = i * i; j <= max_n; j += i){
                prime[j] = 0;
            }
        }
    }
    for(int i = 2; i <= 200 ; i++){
        if(prime[i]) primes.push_back(i);
    }
}
void backTracking(int sum, int idx){
    if(current.size() == n && sum == s){
        res.push_back(current);
        return;
    }
    else if(sum > s || current.size() >= n) return;
    else{
        for(int i = idx; i < primes.size(); i++){
            if (primes[i] > s) break; 
            current.push_back(primes[i]);
            backTracking(sum + primes[i], i + 1);
            current.pop_back();
        }
    }
}
void TestCase(){
    cin >> n >> p >> s;
    res.clear();
    current.clear();
    auto start = lower_bound(primes.begin(), primes.end(), p + 1) - primes.begin();
    backTracking(0, start);
    cout << res.size() << endl;
    sort(res.begin(), res.end());
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
        cout << "\n";
    }
    return 0;
}
/* No Code - No Bug */