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
bool isFullTree(TreeNode* root){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    else if(root->left == NULL || root->right == NULL){
        return false;
    }
    else return isFullTree(root->left) && isFullTree(root->right);
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
        else{
            insertNode(root, u, v, c);
        }
    }
    if(isFullTree(root)){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
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