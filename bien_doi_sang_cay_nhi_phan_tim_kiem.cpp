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
void makeNode(TreeNode* root, int u, int v, char c){
    if(c == 'L') root->left = new TreeNode(v);
    else root->right = new TreeNode(v);
}
void insertNode(TreeNode* root, int u, int v, char c){
    if(root == NULL){
        return;
    }
    if(root->val == u){
        makeNode(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
void Postorder(TreeNode* root, vector<int>& nums){
    if(root != NULL){
        Postorder(root->left, nums);
        nums.push_back(root->val);
        Postorder(root->right, nums);
    }
}
void Inorder(TreeNode* root){
    if(root != NULL){
        Inorder(root->left);
        cout << root->val << " ";
        Inorder(root->right);
    }
}
TreeNode* buildBalanceSearchTree(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(root->val > val){
       root->left = buildBalanceSearchTree(root->left, val);
    } 
    else if(root->val < val) root->right = buildBalanceSearchTree(root->right, val);
    return root;

}
void TestCase(){
    int n;
    cin >> n;
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new TreeNode(u);
            makeNode(root, u, v, c);
        }
        else insertNode(root, u, v, c);
    }
    vector<int> nums;
    Postorder(root, nums);
    TreeNode* node = NULL;
    for(int i = 0; i < nums.size(); i++){
        node = buildBalanceSearchTree(node, nums[i]);
    }
    Inorder(node);
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