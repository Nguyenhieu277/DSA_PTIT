#include <bits/stdc++.h>
using namespace std;

int countGoodSubstrings(const string& s) {
    int n = s.size();
    vector<int> isGood(n, 0);  // Đánh dấu vị trí thuộc về ít nhất 1 xâu đối xứng
    
    // Tìm các cặp đối xứng "AA" hoặc "BB"
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            isGood[i] = 1;
            isGood[i + 1] = 1;
        }
    }
    
    // Tìm các cặp đối xứng dạng "ABA" hoặc "BAB"
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1] && s[i - 1] != s[i]) {
            isGood[i - 1] = 1;
            isGood[i] = 1;
            isGood[i + 1] = 1;
        }
    }
    
    // Đếm số xâu con tốt
    int result = 0, length = 0;
    for (int i = 0; i < n; i++) {
        if (isGood[i]) {
            length++;
            result += length;
        } else {
            length = 0;
        }
    }
    return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << countGoodSubstrings(s) << endl;
    return 0;
}
