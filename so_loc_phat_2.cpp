#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

bool cmp(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    else return a < b;
}
void locphat(int n){
    vector<string> res;
    queue<string> q;
    q.push("6");
    q.push("8");
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(s.size() > n){
            break;
        }
        res.push_back(s);
        q.push(s + "6");
        q.push(s + "8");
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end(), cmp);
    for(string it : res){
        cout << it << " ";
    }
    cout << endl;

}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        locphat(n);
    }
    return 0;
}
/* No Code - No Bug */