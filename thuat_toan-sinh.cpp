#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, flag = 0, a[max_n];
int N;
void init(){
    for(int i = 1; i <= N; i++){
        a[i] = 0;
    }
}
void generate(){
    int i = N;
    while(i > 0 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if(i == 0){
        flag = 1;
    }
    else{
        a[i] = 1;
    }
}
int main(){
    Quick();
    cin >> n;
    flag = 0;
    N = (n + 1) / 2;
    init();
    while(!flag){
        for(int i = 1; i <= N; i++){
            cout << a[i] << " ";
        }
        for(int i = N - (n % 2 == 0 ? 0 : 1); i >= 1; i--){
            cout << a[i] << " ";
        }
        generate();
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */