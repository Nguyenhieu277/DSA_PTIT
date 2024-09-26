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
void buildTree(TreeNode* root, int u, int v, char c){
    if(c == 'L') root->left = new TreeNode(v);
    else root->right = new TreeNode(v);
}
void insert(TreeNode* root, int u, int v, char c){
    if(root == NULL){
        return;
    }
    if(root->val == u){
        buildTree(root, u, v, c);
    }
    else{
        insert(root->left, u, v, c);
        insert(root->right, u, v, c);
    }
}
void LevelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    cout << root->val << " ";
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left != NULL){
            q.push(node->left);
            cout << node->left->val << " ";
        }
        if(node->right != NULL){
            q.push(node->right);
            cout << node->right->val << " ";
        }
    }
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
            buildTree(root, u, v, c);
        } 
        else insert(root, u, v, c);
    }
    LevelOrder(root);
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