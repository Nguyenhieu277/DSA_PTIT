#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void selectionSort(vector<int> &v, int n){
    // Lặp qua từng phần tử trong vector trừ phần tử cuối cùng
    for(int i = 0; i < n - 1; i++){
        int idx = i; // Giả sử chỉ số hiện tại là nhỏ nhất
        // Lặp qua các phần tử còn lại để tìm phần tử nhỏ nhất
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[idx]){
                idx = j; // Cập nhật idx nếu tìm thấy phần tử nhỏ hơn
            }
        }
        // Hoán đổi phần tử nhỏ nhất tìm được với phần tử hiện tại
        if(i != idx){
            swap(v[i], v[idx]);
        }
        // In ra trạng thái hiện tại của vector sau mỗi bước
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