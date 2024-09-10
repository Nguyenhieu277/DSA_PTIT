#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void insertionSort(vector<int> &v, int n){ 
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && v[j - 1] > v[j]){
            swap(v[j], v[j - 1]);
            j--;
        }
        out << "Buoc " << i << ": ";
        for(int k = 0; k <= i; k++){
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
    insertionSort(v, n);
    return 0;
}
