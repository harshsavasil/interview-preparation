#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* child;
    Node () {
        next = NULL;
        child = NULL;
    }
};
class LinkedList {
    public:
        Node* head;
        LinkedList() {
            head = NULL;
        }

        void displayList() {
            Node* temp = new Node();
            temp = head;
            cout << "Linked List ---->" << endl;
            if (temp == NULL) {
                cout << "Linked List is Empty." << endl;
                return;
            }
            while(temp->next != NULL) {
                cout << temp->data << ", ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
        void displayChildList() {
            Node* temp = new Node();
            temp = head;
            cout << "Linked List ---->" << endl;
            if (temp == NULL) {
                cout << "Linked List is Empty." << endl;
                return;
            }
            while(temp->child != NULL) {
                cout << temp->data << ", ";
                temp = temp->child;
            }
            cout << temp->data << endl;
        }

        void insert(int value) {
            Node* temp = new Node();
            if (head == NULL) {
                temp->data  = value;
                head = temp;
                return;
            }
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;                
            }
            Node* newNode = new Node();
            newNode->data = value;
            temp->next = newNode;
        }
        void insertChiild(int value) {
            Node* temp = new Node();
            if (head == NULL) {
                temp->data  = value;
                head = temp;
                return;
            }
            temp = head;
            while(temp->child != NULL) {
                temp = temp->child;                
            }
            Node* newNode = new Node();
            newNode->data = value;
            temp->child = newNode;
        }
};

int main(void) {
    LinkedList mainList, ll1, ll2, ll3;
    mainList.insert(1);
    mainList.insert(2);
    mainList.insert(3);
    mainList.insert(4);
    mainList.insert(5);
    mainList.insert(6);
    ll1.insertChiild(7);
    ll1.insertChiild(8);
    ll1.insertChiild(9);
    ll2.insertChiild(10);
    ll2.insertChiild(11);
    ll3.insertChiild(12);
    mainList.displayList();
    ll1.displayChildList();
    ll2.displayChildList();
    ll3.displayChildList();
    mainList.head->child = ll1.head;
    mainList.head->next->child = ll2.head;
    mainList.head->next->next->child = ll3.head;
    Node* temp;
    temp = mainList.head;
    queue<Node*> nodesQueue;
    while(temp != NULL) {
        nodesQueue.push(temp);
        temp = temp->next;
    }
    while(!nodesQueue.empty()) {
        temp = nodesQueue.front();
        nodesQueue.pop();
        cout << temp->data << ", ";
        if (temp->child) {
            nodesQueue.push(temp->child);
        }
    }
}