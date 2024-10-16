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
void DepthOfTree(TreeNode* root){
    int depth = -1;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        TreeNode* node = tmp.first;
        int currentDepth = tmp.second;
        if(currentDepth > depth){
            depth = currentDepth;
        }
        if(node->left != NULL){
            q.push({node->left, currentDepth + 1});
        }
        if(node->right != NULL){
            q.push({node->right, currentDepth + 1});
        }
    }
    cout << depth << endl;
}
void TestCase(){
    int n;
    cin >> n;
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        root = buildBalanceSearchTree(root, x);
    }
    DepthOfTree(root);
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