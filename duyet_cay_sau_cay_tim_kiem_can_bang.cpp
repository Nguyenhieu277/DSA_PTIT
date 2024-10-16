#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};
TreeNode* buildBalanceSearchTree(TreeNode* root, vector<int>& nums, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    root = new TreeNode(nums[mid]);
    root->left = buildBalanceSearchTree(root->left, nums, start, mid - 1);
    root->right = buildBalanceSearchTree(root->right, nums, mid + 1, end);
    return root;
}
void Postorder(TreeNode* root){
    if(root != NULL){
        Postorder(root->left);
        Postorder(root->right);
        cout << root->val << " ";
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
    sort(nums.begin(), nums.end());
    TreeNode* root = NULL;
    root = buildBalanceSearchTree(root, nums, 0, n - 1);
    Postorder(root);
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