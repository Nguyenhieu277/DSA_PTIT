#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

ll merge(vector<ll> &v, int left, int mid, int right){
    vector<ll> v1(v.begin() + left, v.begin() + mid + 1);
    vector<ll> v2(v.begin() + mid + 1, v.begin() + right + 1);
    int i = 0, j = 0;
    ll cnt = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            v[left] = v1[i++];
            left++;
        }
        else{
            v[left] = v2[j++];
            left++;
            cnt += v1.size() - i;
        }
    }
    while(i < v1.size()){
        v[left] = v1[i++];
        left++;
    }
    while(j < v2.size()){
        v[left] = v2[j++];
        left++;
    }
    return cnt;
}
ll mergeSort(vector<ll> &v, int left, int right){
    ll ans = 0;
    if(left < right){
        int mid = (left + right) / 2;
        ans += mergeSort(v, left, mid); 
        ans += mergeSort(v, mid + 1, right);
        ans += merge(v, left, mid, right);
        return ans;
    }
    return ans;
}
void TestCase(){
    int n;
    cin >> n;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    cout << mergeSort(v, 0, n - 1) << endl;
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