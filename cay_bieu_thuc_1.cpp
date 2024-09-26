#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct TreeNode{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char value) : val(value), left(NULL), right(NULL) {}
};
bool isOperator(char x){
    return x == '+' || x == '-' || x == '*' || x == '/';
}
TreeNode* convert(string str){
    stack<TreeNode*> st;
    for(char c : str){
        if(!isOperator(c)){
            st.push(new TreeNode(c));
        }
        else{
            TreeNode *node1 = st.top();
            st.pop();
            TreeNode* node2 = st.top();
            st.pop();

            TreeNode* node = new TreeNode(c);
            node->left = node2;
            node->right = node1;
            st.push(node);
        }
    }
    return st.top();
}
void inorder(TreeNode *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->val;
        inorder(root->right);
    }
}
void TestCase(){
    string str;
    cin >> str;
    TreeNode *root = convert(str);
    inorder(root);
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