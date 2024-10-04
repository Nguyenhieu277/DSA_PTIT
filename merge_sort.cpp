#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void merge(vector<int>& nums, int left, int mid, int right){
    vector<int> nums1(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> nums2(nums.begin() + mid + 1, nums.begin() + right + 1);
    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] <= nums2[j]){
            nums[left] = nums1[i];
            i++;
        }
        else{
            nums[left] = nums2[j]; 
            j++;
        }
        left++;
    }
    while(i < nums1.size()){
        nums[left++] = nums1[i];
        i++;
    }
    while(j < nums2.size()){
        nums[left++] = nums2[j];
        j++;
    }
}
void mergeSort(vector<int>& nums, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right); 
    }
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }
    mergeSort(nums, 0, n - 1);
    for(int it : nums){
        cout << it << " ";
    }
    cout << endl;
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