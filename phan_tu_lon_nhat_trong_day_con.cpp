#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void slidingWindow(vector<int> &v, int n, int k){
    deque<int> dq;
    for(int i = 0; i < k; i++){
        while(!dq.empty() && v[i] >= v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i = k; i < n; i++){
        cout << v[dq.front()] << " ";
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        while(!dq.empty() && v[i] >= v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << v[dq.front()] << " ";
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        slidingWindow(v, n, k);
    }
    return 0;
}
/* No Code - No Bug */