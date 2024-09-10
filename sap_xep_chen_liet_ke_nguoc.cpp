#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void insertionSort(vector<int> &v, int n, vector<vector<int>> &res){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && v[j] < v[j - 1]){
            swap(v[j], v[j - 1]);
            j--;
        }
        res.push_back(v);
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << "Buoc " << i << ": ";
        for(int j = 0; j <= i; j++){
            cout << res[i][j] << " ";
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
    insertionSort(v, n, res);
    return 0;
}
/* No Code - No Bug */