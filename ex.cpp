#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int binarySearch(vector<int> &nums, int n, int left, int right, int x){
    int mid = (left + right) / 2;
    if(nums[mid] == x){
        return mid + 1;
    }
    else if(nums[mid] < x){
        return binarySearch(nums, n, mid + 1, right, x);
    }
    else return binarySearch(nums, n, left, mid - 1, x);
    return -1;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int x; 
    cin >> x;
    cout << binarySearch(nums, n, 0, n - 1, x) << endl;
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