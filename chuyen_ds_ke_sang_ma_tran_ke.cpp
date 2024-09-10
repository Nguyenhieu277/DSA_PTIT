#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
int matrix[max_n][max_n];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        int word;
        while(ss >> word){
            matrix[i][word] = 1;
            matrix[word][i] = 1;
        } 
    }
}
void output(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << matrix[i][j] << " ";
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