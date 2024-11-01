#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

class AVLNode {
public:
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) {
        this->value = value;
        this->left = this->right = nullptr;
        this->height = 1;
    }
};

class AVLTree {
private:
    AVLNode* treeRoot;

    int height(AVLNode* treeNode) {
        return treeNode ? treeNode->height : 0;
    }

    int getBalance(AVLNode* treeNode) {
        return treeNode ? height(treeNode->left) - height(treeNode->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* addNode(AVLNode* treeNode, int value) {
        if (!treeNode) return new AVLNode(value);

        if (value < treeNode->value)
            treeNode->left = addNode(treeNode->left, value);
        else if (value > treeNode->value)
            treeNode->right = addNode(treeNode->right, value);
        else
            return treeNode;

        treeNode->height = 1 + max(height(treeNode->left), height(treeNode->right));

        int balance = getBalance(treeNode);

        if (balance > 1 && value < treeNode->left->value)
            return rightRotate(treeNode);

        if (balance < -1 && value > treeNode->right->value)
            return leftRotate(treeNode);

        if (balance > 1 && value > treeNode->left->value) {
            treeNode->left = leftRotate(treeNode->left);
            return rightRotate(treeNode);
        }

        if (balance < -1 && value < treeNode->right->value) {
            treeNode->right = rightRotate(treeNode->right);
            return leftRotate(treeNode);
        }

        return treeNode;
    }

    AVLNode* minValueNode(AVLNode* treeNode) {
        AVLNode* current = treeNode;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* treeRoot, int value) {
        if (!treeRoot) return treeRoot;

        if (value < treeRoot->value)
            treeRoot->left = deleteNode(treeRoot->left, value);
        else if (value > treeRoot->value)
            treeRoot->right = deleteNode(treeRoot->right, value);
        else {
            if (!treeRoot->left || !treeRoot->right) {
                AVLNode* temp = treeRoot->left ? treeRoot->left : treeRoot->right;
                if (!temp) {
                    temp = treeRoot;
                    treeRoot = nullptr;
                } else
                    *treeRoot = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(treeRoot->right);
                treeRoot->value = temp->value;
                treeRoot->right = deleteNode(treeRoot->right, temp->value);
            }
        }

        if (!treeRoot) return treeRoot;

        treeRoot->height = 1 + max(height(treeRoot->left), height(treeRoot->right));

        int balance = getBalance(treeRoot);

        if (balance > 1 && getBalance(treeRoot->left) >= 0)
            return rightRotate(treeRoot);

        if (balance > 1 && getBalance(treeRoot->left) < 0) {
            treeRoot->left = leftRotate(treeRoot->left);
            return rightRotate(treeRoot);
        }

        if (balance < -1 && getBalance(treeRoot->right) <= 0)
            return leftRotate(treeRoot);

        if (balance < -1 && getBalance(treeRoot->right) > 0) {
            treeRoot->right = rightRotate(treeRoot->right);
            return leftRotate(treeRoot);
        }

        return treeRoot;
    }

    void preOrder(AVLNode* treeRoot) {
        if (treeRoot) {
            cout << treeRoot->value << " ";
            preOrder(treeRoot->left);
            preOrder(treeRoot->right);
        }
    }

    void inOrder(AVLNode* treeRoot) {
        if (treeRoot) {
            inOrder(treeRoot->left);
            cout << treeRoot->value << " ";
            inOrder(treeRoot->right);
        }
    }

    void destroyTree(AVLNode* treeNode) {
        if (treeNode) {
            destroyTree(treeNode->left);
            destroyTree(treeNode->right);
            delete treeNode;
        }
    }

    bool search(AVLNode* treeNode, int value) {
        if (!treeNode) return false;
        if (value == treeNode->value) return true;
        return value < treeNode->value ? search(treeNode->left, value) : search(treeNode->right, value);
    }

public:
    AVLTree() {
        treeRoot = nullptr;
    }

    ~AVLTree() {
        destroyTree(treeRoot);
    }

    void addNode(int value) {
        treeRoot = addNode(treeRoot, value);
    }

    void deleteNode(int value) {
        treeRoot = deleteNode(treeRoot, value);
    }

    void preOrder() {
        preOrder(treeRoot);
        cout << endl;
    }

    void inOrder() {
        inOrder(treeRoot);
        cout << endl;
    }

    bool search(int value) {
        return search(treeRoot, value);
    }
};

int main() {
    AVLTree tree;

    tree.addNode(10);
    tree.addNode(20);
    tree.addNode(30);
    tree.addNode(40);
    tree.addNode(50);
    tree.addNode(25);

    cout << "Preorder traversal of the constructed AVL tree is: ";
    tree.preOrder();

    cout << "Inorder traversal of the constructed AVL tree is: ";
    tree.inOrder();

    tree.deleteNode(10);
    cout << "Preorder traversal after deletion of 10: ";
    tree.preOrder();

    cout << "Inorder traversal after deletion of 10: ";
    tree.inOrder();

    int valueToSearch = 25;
    cout << "Searching for " << valueToSearch << ": " << (tree.search(valueToSearch) ? "Found" : "Not Found") << endl;

    return 0;
}