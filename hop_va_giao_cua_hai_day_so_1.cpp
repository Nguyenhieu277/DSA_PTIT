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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        set<int> se1;
        set<int> se;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            se1.insert(x);
            se.insert(x);
        }
        set<int> se2;
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            if(se1.find(x) != se1.end()){
                se2.insert(x);
            }
            se.insert(x);
        }
        for(int it : se){
            cout << it << " ";
        }
        cout << endl;
        for(int it : se2){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */