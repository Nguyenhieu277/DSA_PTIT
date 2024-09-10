#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void nextPermutation(string &s){
    int n = s.size();
    int i = n - 2;
    while(i >= 0 && s[i] >= s[i + 1]){
        --i;
    }
    if(i < 0){
        cout << "BIGGEST" << endl;
    }
    else{
        int j = n - 1;
        while(s[i] >= s[j]) --j;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.begin() + n);
        cout << s << endl;
    }
}
void TestCase(){
    int n;
    string s;
    cin >> n >> s;
    cout << n << " ";
    nextPermutation(s);
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