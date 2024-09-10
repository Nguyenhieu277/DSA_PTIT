#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void bubbleSort(vector<int> &v, int n){
    for(int i = 0; i < n - 1; i++){
        int flag = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                flag = 1;
            }
        }
        if(!flag){
            break;
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
    bubbleSort(v, n);
    return 0;
}
/* No Code - No Bug */