#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

class queue {
  private:
    node *front, *back;
  public:
    queue() {
        front = NULL;
        back = NULL;
    }
  public:
    void push_element(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if(front == NULL) {
            front = temp;
            back = temp;
            temp = NULL;
        } else {
            back->next = temp;
            back = temp;
        } 
    }
  public:
    int pop_element() {
        int data = front->data;
        front = front->next;
        return data;
    }
  public:
    void displayQueue() {
        node *temp = new node;
        temp = front;
        while(temp->next != NULL) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin>>n;
    int arr[n][n];
    bool visited[n];
    for(int i=0; i<n; i++) {
        visited[i] = false;
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }   
    }
    queue q;
    q.push_element(1);
    q.push_element(2);
    q.push_element(3);
    q.push_element(4);
    q.push_element(5);
    q.push_element(5);
    q.displayQueue();
    cout<<q.pop_element()<<endl;
    q.displayQueue();
}   