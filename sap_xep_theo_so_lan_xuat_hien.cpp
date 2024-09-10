#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

map<int, int> mp;
bool cmp(int a, int b){
    if(mp[a] != mp[b]){
        return mp[a] > mp[b];
    }
    else return a < b;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        mp.clear();
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
            mp[x]++;
        }
        sort(v.begin(), v.end(), cmp);
        for(int it : v){
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

map<int, int> mp;
bool cmp(int a, int b){
    if(mp[a] != mp[b]){
        return mp[a] > mp[b];
    }
    else return a < b;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        mp.clear();
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
            mp[x]++;
        }
        sort(v.begin(), v.end(), cmp);
        for(int it : v){
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */