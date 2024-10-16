#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};
TreeNode* buildBalanceSearchTree(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(root->val < val){
        root->right = buildBalanceSearchTree(root->right, val);
    }
    else if(root->val > val){
        root->left = buildBalanceSearchTree(root->left, val);
    }
    return root;
}
bool isMiddleNode(TreeNode* root){
    return root != NULL && (root->left != NULL || root->right != NULL);
}
void printMiddle(TreeNode* root, vector<int>& nums){
    if(root == NULL){
        return;
    }
    if(isMiddleNode(root)){
        nums.push_back(root->val);
    }
    printMiddle(root->left, nums);
    printMiddle(root->right, nums);
}
void TestCase(){
    int n;
    cin >> n;
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = buildBalanceSearchTree(root, x);
    }
    vector<int> nums;
    printMiddle(root, nums);
    cout << nums.size();
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