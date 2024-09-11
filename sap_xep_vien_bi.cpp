#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve(string s){
    int x = 0, t = 0, d = 0;
    for(char c : s){
        if(c == 'X') x++;
        else if(c == 'T') t++;
        else d++;
    }
    
    int cnt = 0; 
    for(int i = 0; i < x; i++){
        if(s[i] != 'X') cnt++;
    }
    for(int i = s.size() - d; i < s.size(); i++){
        if(s[i] != 'D') cnt++;
    }
    int a = 0, b = 0;
    for(int i = 0; i < x; i++){
        if(s[i] == 'D') a++;
    } 
    for(int i = s.size() - d; i < s.size(); i++){
        if(s[i] == 'X') b++;
    }
    cout << cnt - min(a, b) << endl;
}

void TestCase(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(s);
}

int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
