#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node () {
        next = NULL;
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

        void reverse() {
            Node* current = head;
            if (current == NULL) {
                cout << "Linked List is Empty." << endl;
                return;
            }
            Node* previous = NULL;
            Node* nextNode = NULL;
            while(current->next != NULL) {
                nextNode = current->next;
                current->next = previous;
                previous = current;
                current = nextNode;
            }
            current->next = previous;
            head = current;
        }

        void insertAtBeginning(int value) {
            Node* temp = new Node();
            temp->data = value;
            if (head == NULL) {
                cout << temp << endl;
                head = temp;
            } else {
                temp->next = head;
                head = temp;
            }
        }

        void insertAtEnd(int value) {
            Node* temp = new Node();
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;                
            }
            Node* newNode = new Node();
            newNode->data = value;
            temp->next = newNode;
        }

        void insertAt(int value, int position) {
            if (position == 0) {
                insertAtBeginning(value);
                return;
            }
            int currentIndex = 0;
            Node* current = new Node();
            Node* previous = new Node();
            current = head;
            previous = head;
            while(current->next != NULL) {
                if (currentIndex == position) {
                    Node* newNode = new Node();
                    newNode->data = value;
                    newNode->next = current;
                    previous->next = newNode;
                    return;
                }
                currentIndex += 1;
                previous = current;                
                current = current->next;
            }
            if (position == currentIndex) {
                Node* newNode = new Node();
                newNode->data = value;
                current->next = newNode;
            }
            else {
                cout << "Position is out of the limit of Linked List." << endl;
            }
        }

        void remove(int position) {
            if(head == NULL) {
                cout << "Empty List" << endl;
                return;
            }
            Node* current = head;
            if (position == 0) {
                head = head->next;
                delete current;
                return;
            }
            for(int index = 0; index < position - 1; index++) {
                current = current->next;
            }
            if (current->next != NULL) {
                current->next = current->next->next;
            } else {
                cout << "Position is out of the index of Linked List." << endl;
            }

        }
};

int main() {
    LinkedList ll;
    ll.displayList();
    ll.insertAtBeginning(1);
    ll.displayList();
    ll.insertAtBeginning(2);
    ll.displayList();
    ll.insertAtEnd(3);
    ll.displayList();
    ll.insertAt(5, 0);
    ll.displayList();
    ll.insertAt(4, 3);
    ll.displayList();
    ll.insertAtEnd(6);
    ll.displayList();
    ll.insertAt(7, 3);
    ll.displayList();
    ll.remove(0);
    ll.displayList();
    ll.remove(5);
    ll.displayList();
    ll.remove(5);
    ll.displayList();
    ll.reverse();
    ll.displayList();
    // ll.insertAtBeginning(1);
    return 0;
}