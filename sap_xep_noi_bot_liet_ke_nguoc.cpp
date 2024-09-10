#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void bubbleSort(vector<int> &v, int n, vector<vector<int>> &res){
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(v[j + 1] < v[j]){
                swap(v[j + 1], v[j]);
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
        res.push_back(v);
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << "Buoc " << i + 1 << ": ";
        for(int it : res[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        vector<vector<int>> res;
        bubbleSort(v, n, res);
    }
    return 0;
}
/* No Code - No Bug */