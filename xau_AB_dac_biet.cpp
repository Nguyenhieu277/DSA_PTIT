#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<string> res;
string tmp = "";
void init(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        tmp.push_back('A');
    }
}
void backTracking(string curr){
    if(curr.size() == n){
        int cnt = 0;
        for(int i = 0; i <= curr.size() - k; i++){
            if(curr.substr(i, k) == tmp){
                cnt++;
            }
        }
        if(cnt == 1){
            res.push_back(curr);
        }
        return;
    }
    backTracking(curr + "A");
    backTracking(curr + "B");
}
void TestCase(){
    init(); 
    string curr = "";
    backTracking(curr);
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */