#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
int a[max_n][max_n];
vector<int> List[max_n];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}
void output(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                List[i].push_back(j);
            }
        }
    } 
    for(int i = 1; i <= n; i++){
        for(int it : List[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    input();
    output();
    return 0;
}
/* No Code - No Bug */