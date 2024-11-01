#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void convert(int n){
    queue<pair<int, int>> q;
    set<int> se;
    q.push({n, 0});
    while(!q.empty()){
        auto top = q.front();
        q.pop();

        int number = top.first, operation = top.second;
        if(number == 1){
            cout << operation << endl;
            return;
        }
        for(int i = 2; i <= sqrt(number); i++){
            if(number % i == 0  && se.find(number / i) == se.end()){
                se.insert(number / i);
                q.push({number / i, operation + 1});
            }
        }
        q.push({number - 1, operation + 1});
    }
}
void TestCase(){
    int n;
    cin >> n;
    convert(n);
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