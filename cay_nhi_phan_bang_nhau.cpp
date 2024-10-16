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
bool isSameTree(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else return root1->val == root2->val && isSameTree(root1->left, root2->left)
                && isSameTree(root1->right, root2->right);
}

void TestCase(){
    int n;
    cin >> n;
    TreeNode* root1 = NULL;
    for(int i = 0; i < n; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        if(root1 == NULL){
            root1 = new TreeNode(u);
            makeNode(root1, u, v, c);
        }
        else insertNode(root1, u, v, c);
    }
    int m;
    cin >> m;
    TreeNode* root2 = NULL;
    for(int i = 0; i < n; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        if(root2 == NULL){
            root2 = new TreeNode(u);
            makeNode(root2, u, v, c);
        }
        else insertNode(root2, u, v, c);
    }
    if(isSameTree(root1, root2)){
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