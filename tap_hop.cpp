#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k, s;
vector<int> nums;
int cnt = 0;
void backTracking(int idx){
    if(nums.size() == k){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum == s){
            cnt++;
        }
        return;
    }
    else{
        for(int i = idx; i <= n; i++){
            nums.push_back(i);
            backTracking(i + 1);
            nums.pop_back();
        }
    }
}
void TestCase(){
    cnt = 0;
    backTracking(1);
    cout << cnt << endl;
}
int main(){
    Quick();
    while(cin >> n >> k >> s){
        if(n == 0 && k == 0 && s == 0){
            break;
        }
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */