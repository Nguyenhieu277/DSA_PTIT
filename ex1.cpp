#include <iostream>
using namespace std;

long long sumFactorials(int n, long long currentFactorial) {
    if (n == 0) return 0;  // Điều kiện dừng: tổng của 0 phần tử là 0
    currentFactorial *= n;  // Tính giai thừa hiện tại: currentFactorial = n!
    return currentFactorial + sumFactorials(n - 1, currentFactorial / n);  // Cộng giai thừa vào tổng và gọi đệ quy
}

int main() {
    int n;
    cin >> n;
    
    // Bắt đầu đệ quy với giai thừa hiện tại là 1
    cout << sumFactorials(n, 1) << endl;
    
    return 0;
}
