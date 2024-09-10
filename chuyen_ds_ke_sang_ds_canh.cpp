#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


int main(){
    Quick();
    int n;
    cin >> n;
    cin.ignore();
    set<pair<int, int>> v;
    for(int i = 1; i <= n; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int word;
        while(ss >> word){
            if(word > i){
                v.insert({i, word});
            }
        }
    }
    for(auto it : v){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
/* No Code - No Bug */