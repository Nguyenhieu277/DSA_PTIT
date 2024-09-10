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
void removeDuplicate(node &head){
    unordered_set<int> se;
    node current = head;
    node prev = NULL;
    while(current != NULL){
        if(se.find(current->val) != se.end()){
            prev->next = current->next;
            delete current;
        }
        else{
            se.insert(current->val);
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
    node head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        insert(head, x);
    }
    removeDuplicate(head);
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