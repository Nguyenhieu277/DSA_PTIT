#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void selectionSort(vector<int> &v, int n){
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
        cout << "Buoc " << i + 1 << ": ";
        for(int k = 0; k < n; k++){
            cout << v[k] << " ";
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
    selectionSort(v, n);
    return 0;
}
/* No Code - No Bug */