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
void spiralOrder(TreeNode* root){
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            TreeNode* top = st1.top();
            st1.pop();
            cout << top->val << " ";
            if(top->right != NULL) st2.push(top->right);
            if(top->left != NULL) st2.push(top->left);
        }
        while(!st2.empty()){
            TreeNode* top = st2.top();
            st2.pop();
            cout << top->val << " ";
            if(top->left != NULL) st1.push(top->left);
            if(top->right != NULL) st1.push(top->right);
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
            makeNode(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    spiralOrder(root);
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