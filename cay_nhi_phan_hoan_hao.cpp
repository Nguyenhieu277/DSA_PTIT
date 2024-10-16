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

    TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};
void makeNode(TreeNode* root, int u, int x, int c){
    if(c == 'L') root->left = new TreeNode(x);
    else root->right = new TreeNode(x);
}
void insertNode(TreeNode* root, int u, int x, int c){
    if(root == NULL){
        return;
    }
    if(root->val == u){
        makeNode(root, u, x, c);
    }
    else{
        insertNode(root->left, u, x, c);
        insertNode(root->right, u, x, c);
    }
}
int CalculateDepth(TreeNode* root){
    int depth = 0;
    while(root != NULL){
        depth++;
        root = root->left;
    }
    return depth;
}
bool isPerfectTree(TreeNode* root, int depth, int level = 0){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        return depth == level + 1;
    }
    else if(root->left == NULL || root->right == NULL){
        return false;
    }
    else return isPerfectTree(root->left, depth, level + 1) && isPerfectTree(root->right, depth, level + 1);
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
            makeNode(root,u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    int depth = CalculateDepth(root);
    if(isPerfectTree(root, depth)){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
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