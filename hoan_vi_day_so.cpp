#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<int> nums, curr;
bool visited[max_n];
void backTrack(int idx){
    if(curr.size() == n){
        for(int i = 0; i < n; i++){
            cout << curr[i] << " ";
        }
        cout << endl;
        return;
    }
    else{
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                curr.push_back(nums[i]);
                backTrack(idx);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
}
int main(){
    Quick();
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    backTrack(0);
    return 0;
}
/* No Code - No Bug */