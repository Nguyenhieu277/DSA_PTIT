#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

vector<int> leftIdx(vector<int> &v, int n){
    stack<int> st;
    vector<int> left(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    return left;
}
vector<int> rightIdx(vector<int> &v, int n){
    stack<int> st;
    vector<int> right(n);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }
    return right;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    vector<int> left = leftIdx(v, n);
    vector<int> right = rightIdx(v, n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, (ll)v[i] * (right[i] - left[i] - 1));
    }
    cout << ans << endl;
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