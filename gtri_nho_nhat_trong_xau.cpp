#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/


void TestCase(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for(char c : s){
        mp[c]++;
    }
    priority_queue<int> q;
    for(auto it : mp){
        if(it.second > 0){
            q.push(it.second);
        }
    }
    while(k--){
        int top = q.top();
        q.pop();
        top--;
        q.push(top);
    }
    ll sum = 0;
    while(!q.empty()){
        sum += pow(q.top(), 2);
        q.pop();
    }
    cout << sum << endl;
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