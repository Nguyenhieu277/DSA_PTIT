#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


// Hàm thực hiện thuật toán sắp xếp nổi bọt
void bubbleSort(vector<int> &v, int n){
    // Lặp qua các phần tử của mảng
    for(int i = 0; i < n - 1; i++){
        // Khởi tạo cờ hiệu để kiểm tra xem có hoán đổi nào xảy ra không
        int flag = 0;
        // Lặp qua các phần tử chưa được sắp xếp
        for(int j = 0; j < n - i - 1; j++){
            // Nếu phần tử hiện tại lớn hơn phần tử kế tiếp
            if(v[j] > v[j + 1]){
                // Hoán đổi hai phần tử
                swap(v[j], v[j + 1]);
                // Đặt cờ hiệu để chỉ ra rằng đã có hoán đổi
                flag = 1;
            }
        }
        // Nếu không có hoán đổi nào xảy ra, thoát khỏi vòng lặp
        if(!flag){
            break;
        }
        // In ra trạng thái của mảng sau mỗi bước
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