#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<char> alpha(max_n);
vector<char> curr;
void init(){
    cin >> n >> k;
    alpha.resize(n + 1);
    curr.clear();
    for(int i = 1; i <= n; i++){
        alpha[i] = 'A' + i - 1;
    }
}
void backTrack(int idx){
    if(curr.size() == k){
        for(int i = 0; i < curr.size(); i++){
            cout << curr[i];
        }
        cout << endl;
        return;
    }
    else{
        for(int i = idx; i <= n; i++){
            curr.push_back(alpha[i]);
            backTrack(i + 1);
            curr.pop_back();
        }
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        init();
        backTrack(1);
    }
    return 0;
}
/* No Code - No Bug */