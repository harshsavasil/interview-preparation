#include <iostream>
#include <unordered_map>
using namespace std;

class DoublyLinkedListNode {
   public:
    string key;
    int value;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(string key, int value) {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
    void removeBindings() {
        if (this->prev != NULL) {
            this->prev->next = this->next;
        }
        if (this->next != NULL) {
            this->next->prev = this->prev;
        }
        this->prev = NULL;
        this->next = NULL;
    }
};
class DoublyLinkedList {
   public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;

    DoublyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    void setHeadTo(DoublyLinkedListNode* node) {
        if (head == node) {
            return;
        } else if (this->head == NULL) {
            this->head = node;
            this->tail = node;
            return;
        } else if (this->head == this->tail) {
            this->head = node;
            this->head->next = this->tail;
            return;
        } else {
            if (this->tail == node) {
                this->removeTail();
            }
            node->removeBindings();
            node->next = this->head;
            this->head->prev = node;
            this->head = node;
        }
    }
    void removeTail() {
        if (this->tail == NULL) return;
        if (this->tail == this->head) {
            this->tail = NULL;
            this->head = NULL;
            return;
        }
        this->tail = this->tail->prev;
        this->tail->next = NULL;
    }
};
class LRUCache {
   public:
    int maxSize;
    int currentCount;
    DoublyLinkedList* listOfMostRecent;
    unordered_map<string, DoublyLinkedListNode*> cache;

    LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
        this->currentCount = 0;
        this->listOfMostRecent = new DoublyLinkedList();
    }
    void insertKeyValuePair(string key, int val) {
        // check if the key exists.
        // if it exists then just update the value and the LL.
        // if not present, check for the value of current number of keys
        // if it is less than max size then just insert the value and update map
        // else delete the least recently used value and insert into LL and update map
        if (this->cache.find(key) != this->cache.end()) {
            this->cache[key]->value = val;
            this->listOfMostRecent->setHeadTo(this->cache[key]);
        } else {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(key, val);
            if (this->currentCount == this->maxSize) {
                this->listOfMostRecent->removeTail();
                this->currentCount--;
            }
            this->listOfMostRecent->setHeadTo(node);
            this->cache[key] = node;
            this->currentCount++;
        }
    }

    int* getValueFromKey(string key) {
        // Write your code here.
        if (this->cache.find(key) != this->cache.end()) {
            this->listOfMostRecent->setHeadTo(this->cache[key]);
            return &this->cache[key]->value;
        }
        return NULL;
    }

    string getMostRecentKey() {
        // Write your code here.
        return this->listOfMostRecent->head->key;
    }
};

int main() {
    return 0;
}