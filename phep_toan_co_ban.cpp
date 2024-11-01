#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int sign[] = {'+', '-'};
bool isCorrect(string str){
    int x = stoi(str.substr(0, 2));
    int y = stoi(str.substr(5, 2));
    int z = stoi(str.substr(10, 2));
    if(x < 10 || y < 10 || z < 10){
        return false;
    }
    if(str[3] == '+'){
        return x + y == z;
    }
    else if(str[3] == '-'){
        return x - y == z;
    }
}
void backTracking(string str, int idx, int n, int& flag){
    if(flag) return;
    if(idx == n){
        if(isCorrect(str)){
            cout << str << endl;
            flag = 1;
        }
        return;
    }
    if(str[idx] == '?'){
        if(idx == 3){
            for(int i = 0; i <= 1; i++){
                str[idx] = sign[i];
                backTracking(str, idx + 1, n, flag);
            }
        }
        else{
            for(int i = 0; i <= 9; i++){
                str[idx] = i + '0';
                backTracking(str, idx + 1, n, flag);
            }
        }
        str[idx] = '?';
    }
    else{
        backTracking(str, idx + 1, n, flag);
    }
}
void TestCase(){
    string str;
    getline(cin, str);
    int n = str.size();
    for(int i = 0; i < n; i++){
        if(str[i] == '/' || str[i] == '*'){
            cout << "WRONG PROBLEM!" << endl;
            return;
        }
    }
    int flag = 0;
    backTracking(str, 0, n, flag);
    if(!flag){
        cout << "WRONG PROBLEM!" << endl;
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */