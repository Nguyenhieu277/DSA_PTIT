#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<string> strs;
vector<string> nums;
int visited[max_n];
vector<int> tmp;
int minElement = INT_MAX;
void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            nums[i][j] = strs[i][tmp[j]];
        }
    }
    sort(nums.begin(), nums.end());
    int maxVal = stoi(nums[n - 1]);
    int minVal = stoi(nums[0]);
    int diff = maxVal - minVal;
    minElement = min(minElement, diff);
}
void backTracking(int idx){
    if(idx == k){
        solve();
        return;
    }
    else{
        for(int i = 0; i < k; i++){
            if(!visited[i]){
                visited[i] = 1;
                tmp.push_back(i);
                backTracking(idx + 1);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
    }
}
void TestCase(){
    cin >> n >> k;
    strs.clear();
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        strs.push_back(s);
        nums.push_back(s);
    }
    backTracking(0);
    cout << minElement << endl;
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */