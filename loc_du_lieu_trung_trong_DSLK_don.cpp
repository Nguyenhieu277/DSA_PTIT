#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Node{
    int val;
    Node* next;
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
        return;
    }
    else{
        node tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void fillValue(node &head){
    set<int> frequency;
    node prev = NULL;
    node current = head;
    while(current != NULL){
        if(frequency.find(current->val) != frequency.end()){
            prev->next = current->next;
            node tmp = current;
            current = current->next;
            delete tmp;
        }
        else{
            frequency.insert(current->val);
            prev = current;
            current = current->next;
        }
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
    fillValue(head);
    printNode(head);
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */