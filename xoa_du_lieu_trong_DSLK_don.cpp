#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Node{
    int val;
    Node *next;
};
typedef Node* node;
node makeNode(int x){
    node newNode = new Node;
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}
void insert(node &head, int x){
    node newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
    }
    else{
        node tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void removeValue(node &head, int x){
    while(head != NULL && head->val == x){
        node tmp = head;
        head = head->next;
        delete tmp;
    }
    node current = head;
    node prev = NULL;
    while(current != NULL){
        if(current->val == x){
            prev->next = current->next;
            delete current;
        }
        else{
            prev = current;
        }
        current = prev->next;
    }
}
void printNode(node head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void TestCase(){
    int n;
    cin >> n;
    node head = NULL;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        insert(head, x);
    }
    int x; cin >> x;
    removeValue(head, x);
    printNode(head);
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */