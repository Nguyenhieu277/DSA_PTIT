#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void solve(int n, int s){
    if(s > 9 * n || (s == 0 && n > 1)){
        cout << "-1 -1" << endl;
        return;
    }
    int Min[n + 1] = {0}, Max[n + 1] = {0};
    int tmp = s;
    for(int i = 1; i <= n; i++){
        if(tmp > 9){
            Max[i] = 9;
            tmp -= 9;
        }
        else{
            Max[i] = tmp;
            tmp = 0;
        }
    }
    --s;
    for(int i = n; i >= 2; i--){
        if(s > 9){
            Min[i] = 9;
            s -= 9;
        }
        else{
            Min[i] = s;
            s = 0;
        }
    }
    Min[1] = (s + 1);
    for(int i = 1; i <= n; i++){
        cout << Min[i];
    }
    cout << " ";
    for(int i = 1; i <= n; i++){
        cout << Max[i];
    }
    cout << endl;
}
void TestCase(){
    int n, s;
    cin >> n >> s;
    solve(n, s);
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