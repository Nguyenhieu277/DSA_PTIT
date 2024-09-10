#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void selectionSort(vector<int> &v, int n, vector<vector<int>> &res){
    for(int i = 0; i < n - 1; i++){
        int idx = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[idx]){
                idx = j;
            }
        }
        if(i != idx){
            swap(v[i], v[idx]);
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
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    vector<vector<int>> res;
    selectionSort(v, n, res);
    return 0;
}
/* No Code - No Bug */