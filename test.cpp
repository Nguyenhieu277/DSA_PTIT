#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

void merge(vector<int>& nums1, vector<int>& nums2){
    int i = 0, j = 0;
    vector<int> res;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] <= nums2[j]){
            res.push_back(nums1[i]);
            i++;
        }
        else{
            res.push_back(nums2[j]);
            j++;
        }
    }
    while(i < nums1.size()){
        res.push_back(nums1[i]);
        i++;
    }
    while(j < nums2.size()){
        res.push_back(nums2[j]);
        j++;
    }
    for(int it : res){
        cout << it << " ";
    }
    cout << endl;
}
void TestCase(){
    int n;
    cin >> n;
    vector<int> nums1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums1.push_back(x);
    }
    int m;
    cin >> m;
    vector<int> nums2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums2.push_back(x);
    }
    merge(nums1, nums2);
    
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */