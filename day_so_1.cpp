#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        if (i > 0) cout << " ";
        cout << vec[i];
    }
    cout << "]" << " ";
}

int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            nums.push_back(x);
        }
        vector<vector<int>> res;
        res.push_back(nums);
        vector<int> curr = nums;
        while(curr.size() > 1){
            vector<int> next;
            for(int i = 0; i < curr.size() - 1; i++){
                next.push_back(curr[i] + curr[i + 1]);
            }
            res.push_back(next);
            curr = next;
        }
        reverse(res.begin(), res.end());
        for(auto it : res){
            printVector(it);
        }
        cout << endl;
    }
    return 0;
}
/* No Code - No Bug */