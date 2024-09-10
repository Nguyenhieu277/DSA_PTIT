#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string hotPotato(vector<string> &namelist, int num){
    queue<string> q;
    for(auto it : namelist){
        q.push(it);
    }
    while(q.size() > 1){
        for(int i = 0; i < num; i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}
void TestCase(){
    vector<string> namelist = {"Bill", "David", "Susan", "Jane", "Kent", "Brad"};
    int num = 7;
    cout << "The winner is: " << hotPotato(namelist, num) << endl;
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */