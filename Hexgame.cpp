#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vi xoaytrai(vi a){
    vi b(6);
    b[0] = a[3];
    b[1] = a[0];
    b[2] = a[2];
    b[3] = a[4];
    b[4] = a[1];
    b[5] = a[5];
    return b;
}

vi xoayphai(vi a){
    vi b(6);
    b[0] = a[0];
    b[1] = a[4];
    b[2] = a[1];
    b[3] = a[3];
    b[4] = a[5];
    b[5] = a[2];
    return b;
}

int bfs(vi s, vi t){
    queue<pair<vi, int>> q;
    set<vi> se;
    q.push({s, 0});
    se.insert(s);
    while(!q.empty()){
        pair<vi, int> tmp = q.front(); q.pop();
        vi x = tmp.first;
        if(x == t) return tmp.second;
        vi trai = xoaytrai(x);
        if(se.count(trai) == 0){
            q.push({trai, tmp.second + 1});
            se.insert(trai);
        }
        vi phai = xoayphai(x);
        if(se.count(phai) == 0){
            q.push({phai, tmp.second + 1});
            se.insert(phai);
        }
    }
    return -1;
}

int main(){
    Quick();
    vi s(6), t(6);
    for(int i = 0; i < 6; i++) cin >> s[i];
    for(int i = 0; i < 6; i++) cin >> t[i];
    cout << bfs(s, t) << endl;
}

/* No Code - No Bug */