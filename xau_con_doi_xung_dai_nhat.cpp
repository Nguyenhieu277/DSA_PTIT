#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void longestPalindromeSubstring(const string& str){
    int ans = INT_MIN;
    for(int i = 0; i < str.size(); i++){
        int left = i, right = i;
        while(left >= 0 && right < str.size() && str[left] == str[right]){
            if(ans < (right - left + 1)){
                ans = right - left + 1;
            }
            left--; right++;
        }
        int left = i, right = i + 1;
        while(left >= 0 && right < str.size() && str[left] == str[right]){
            if(ans < (right - left + 1)){
                ans = right - left + 1;
            }
            left--; right++;
        }
    }
    cout << ans << endl;
}
void TestCase(){
    string str;
    cin >> str;
    longestPalindromeSubstring(str);
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */