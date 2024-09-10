#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

map<vector<int>, int> mp;
int n, flag = 0;
vector<int> nums;
vector<int> a;
void init(){
    flag = 0;
    a.clear();
    nums.clear();
    mp.clear();
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    for(int i = 0; i < n; i++){
        a.push_back(i + 1);
    }
}
void generate(){
    int i = n - 2;
    while(i >= 0 && a[i] >= a[i + 1]){
        --i;
    }
    if(i < 0){
        flag = 1;
    }
    else{
        int j = n - 1;
        while(a[i] > a[j]) --j;
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
    }
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        init();
        int i = 1;
        while(!flag){
            mp[a] = i;
            i++;
            generate();
        }
        cout << mp[nums] << endl;
    }
    return 0;
}
/* No Code - No Bug */