#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int convertFiveToSix(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '5'){
            s[i] = '6';
        }
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}
int convertSixToFive(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '6'){
            s[i] = '5';
        }
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}
ll solveMax(string a, string b){
    int n1 = convertFiveToSix(a);
    int n2 = convertFiveToSix(b);
    return n1 + n2; 
}
ll solveMin(string a, string b){
    int n1 = convertSixToFive(a);
    int n2 = convertSixToFive(b);
    return n1 + n2; 
}
int main(){
    Quick();
    string a, b;
    cin >> a >> b;
    cout << solveMin(a, b) << " " << solveMax(a, b) << endl;
    return 0;
}
/* No Code - No Bug */