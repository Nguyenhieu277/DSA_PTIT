#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct node{
    int val;
    node* next;
};
typedef node* Node;
Node makeNode(int x){
    Node tmp = new node;
    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}
void insert(Node &head, int x){
    if(head == NULL){
        Node tmp = makeNode(x);
        head = tmp;
        return;
    }
    Node newNode = makeNode(x);
    Node tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void removeValue(Node &head, int x){
    Node prev = NULL;
    Node current = head;
    while(current != NULL){
        if(current->val == x){
            Node tmp = current;
            if(prev == NULL){
                head = current->next;
            }
            else{
                prev->next = current->next;
            }
            current = current->next;
            delete tmp;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
}
void printNode(Node head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void TestCase(){
    Node head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        insert(head, x);
    }
    int x;
    cin >> x;
    removeValue(head, x);
    printNode(head);
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */