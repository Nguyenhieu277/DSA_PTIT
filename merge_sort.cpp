#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void merge(vector<int> &v, int left, int mid, int right){
    vector<int> v1(v.begin() + left, v.begin() + mid + 1);
    vector<int> v2(v.begin() + mid + 1, v.begin() + right + 1);
    int n = v1.size(), m = v2.size();
    int i = 0, j = 0;
    while(i < n && j < m){
        if(v1[i] <= v2[j]){
            v[left] = v1[i++];
        }
        else{
            v[left] = v2[j++];
        }
        left++;
    }
    while(i < n){
        v[left] = v1[i++];
        left++;
    }
    while(j < m){
        v[left] = v2[j++];
        left++;
    }
}
void mergeSort(vector<int> &v, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
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
        mergeSort(v, 0, n - 1);
        for(int it : v){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */