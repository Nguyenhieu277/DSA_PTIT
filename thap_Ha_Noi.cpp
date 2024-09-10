#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void backTracking(int n, char a, char b, char c){
    if(n == 1){
        cout << a << " -> " << c << endl;
        return;
    }
    backTracking(n - 1, a, c, b);
    backTracking(1, a, b, c);
    backTracking(n - 1, b, a, c);
}
int main(){
    Quick();
    int n;
    cin >> n;
    backTracking(n, 'A', 'B', 'C');
    return 0;
}
/* No Code - No Bug */