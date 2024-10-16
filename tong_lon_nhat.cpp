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
        if(root->left != NULL) insertNode(root->left, u, v, c);
        if(root->right != NULL) insertNode(root->right, u, v, c);
    }
}
int res = INT_MIN;
int findMaximumSum(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    int leftSum = findMaximumSum(root->left);
    int rightSum = findMaximumSum(root->right);
    if(root->right != NULL && root->left != NULL){
        res = max(res, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) + root->val;
    }
    return root->left == NULL ? rightSum + root->val : leftSum + root->val;
}
void TestCase(){
    int n;
    cin >> n;
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new TreeNode(u);
            makeNode(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    res = INT_MIN;
    findMaximumSum(root);
    cout << res << endl;
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