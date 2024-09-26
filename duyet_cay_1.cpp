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
TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int n, unordered_map<int, int> &mp, int start, int end, int &idx){
    if(start > end) return NULL; 
    int rootVal = preorder[idx++];
    TreeNode* root = new TreeNode(rootVal);

    int inIdx = mp[rootVal];
    root->left = buildTree(inorder, preorder, n, mp, start, inIdx - 1, idx);
    root->right = buildTree(inorder, preorder, n, mp, inIdx + 1, end, idx);
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
    unordered_map<int, int> mp;
    vector<int> inorder, preorder;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x] = i;
        inorder.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        preorder.push_back(x);
    }
    TreeNode* root = NULL;
    int idx = 0;
    root = buildTree(inorder, preorder, n, mp, 0, n - 1, idx);
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