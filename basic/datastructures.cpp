#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linkedList {
  private:
    node *head, *tail;

  public:
    linkedList() {
        head = NULL;
        tail = NULL;
    }

  public:
    void createNode(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

  public:
    void displayLinkedList()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
  public:
    int deleteFirstOccurenceFromLeft(int value) {
        if (head->data == value) {
            head = head->next;
            return 1;
        }
        node *current = new node; // start from second element
        node *prev = new node;
        prev = head;
        current = head->next;
        while(current != NULL) {
            if (current->data == value) {
                prev->next = current->next;
                current = NULL;
                return 1;
            }
            prev = current;
            current = current->next;
        }
        return 0;
    }
  public:
    int deleteAllOccurences(int value) {
        int count = 0;
        if (head->data == value) {
            head = head->next;
            count += 1;
        }
        node *current = new node; // start from second element
        node *prev = new node;
        prev = head;
        current = head->next;
        while(current != NULL) {
            if (current->data == value) {
                prev->next = current->next;
                current = NULL;
                return 1;
            }
            prev = current;
            current = current->next;
        }
        return 0;
    }
};

class stack {
  private:
    node *top;
  public:
    stack() {
        top = NULL;
    }
  public:
    void push(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if(top == NULL) {
            top = temp;
            temp = NULL;
        } else {
            temp->next = top;
            top = temp;
            // node *movingNode = new node;
            // movingNode = top;
            // while(movingNode->next != NULL) {
            //     movingNode = movingNode->next;
            // }
            // movingNode->next = temp; 
        }
    }
  public:
    int pop() {
        if(top == NULL) {
            cout<<"Stack Underflow."<<endl;
            return -1;
        }
        cout<<"top:"<<top->data<<endl;
        int top_value = top->data; 
        top = top->next;
        return top_value;
    }
  public:
    void displayStack() {
        node *movingNode = new node;
        movingNode = top;
        if (top == NULL) {
            cout<<"Empty Stack"<<endl;
            return;
        }
        while(movingNode->next != NULL) {
            cout<<movingNode->data<<"<--";
            movingNode = movingNode->next;
        }
        cout<<movingNode->data<<endl;
    }
};

int main()
{
    // array implementation
    // int arr[5] = {1, 2, 4, 5, 5};
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    // linked list implementation
    // linkedList new_list;
    // new_list.createNode(1);
    // new_list.createNode(2);
    // new_list.createNode(3);
    // new_list.createNode(4);
    // new_list.createNode(5);
    // new_list.createNode(4);
    // new_list.createNode(6);
    // new_list.displayLinkedList();
    // new_list.deleteFirstOccurenceFromLeft(1);
    // new_list.displayLinkedList();
    // new_list.deleteFirstOccurenceFromLeft(2);
    // new_list.displayLinkedList();
    // new_list.deleteFirstOccurenceFromLeft(5);
    // new_list.displayLinkedList();
    // stack new_stack;
    // new_stack.push(1);
    // new_stack.push(2);
    // new_stack.push(3);
    // new_stack.push(4);
    // new_stack.push(5);
    // new_stack.push(6);
    // new_stack.push(7);
    // new_stack.displayStack();
    // new_stack.pop();
    // new_stack.displayStack();
    // new_stack.pop();
    // new_stack.pop();
    // new_stack.displayStack();
    // new_stack.pop();
    // new_stack.displayStack();
    return 0;
}