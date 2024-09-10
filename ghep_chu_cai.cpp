#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<char> v, curr;
int visited[max_n];
void init(char x){
    for(char i = 'A'; i <= x; i++){
        v.push_back(i);
    }
}
bool check(vector<char> &v){
    for(int i = 1; i <= v.size() - 2; i++){
        if(v[i] == 'A' || v[i] == 'E'){
            if(v[i - 1] != 'A' && v[i + 1] != 'E' && v[i - 1] != 'E' && v[i + 1] != 'A'){
                return false;
            }
        }
    }
    return true;
}
void backTracking(int idx){
    if(curr.size() == v.size()){
        if(check(curr)){
            for(int i = 0; i < curr.size(); i++){
                cout << curr[i];
            }
            cout << endl;
        }
        return;
    }
    else{
        for(int i = idx; i < v.size(); i++){
            if(!visited[i]){
                curr.push_back(v[i]);
                visited[i] = 1;
                backTracking(idx);
                curr.pop_back();
                visited[i] = 0;
            }
        }
    }
}
int main(){
    Quick();
    char x;
    cin >> x;
    init(x);
    backTracking(0);
    return 0;
}
/* No Code - No Bug */