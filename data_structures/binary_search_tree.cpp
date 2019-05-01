#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct bstNode {
    int data;
    bstNode* left;
    bstNode* right;
    bstNode() {
        left = NULL;
        right = NULL;
    }
};

bool isBST(bstNode* root, int minValue, int maxValue) {
    if (root == NULL) return true;
    // cout << root->data << ": " << minValue << ": " << maxValue << endl;
    if (root->data > minValue && root->data <= maxValue &&
        isBST(root->left, minValue, root->data) && isBST(root->right, root->data, maxValue)) {
        return true;
    }
    return false;
}

class BinarySearchTree {
    public:
        bstNode* root;
        BinarySearchTree() {
            root = NULL;
        }
        void insert(int value){
            bstNode* tempNode = new bstNode();
            tempNode->data = value;
            if (root == NULL) {
                root = tempNode;
                return;
            }
            bstNode* indexPointer;
            indexPointer = root;
            while(indexPointer != NULL) {
                if(value <= indexPointer->data) {
                    if (indexPointer->left == NULL) {
                        indexPointer->left = tempNode;
                        return;
                    }
                    indexPointer = indexPointer->left;
                }
                else {
                    if (indexPointer->right == NULL) {
                        indexPointer->right = tempNode;
                        return;
                    }
                    indexPointer = indexPointer->right;
                }
            }
        }
        bool search(int value){
            bstNode* indexPointer;
            indexPointer = root;
            while(indexPointer != NULL) {
                if(value == indexPointer->data) {
                    return true;
                }
                else if (value < indexPointer->data) {
                    indexPointer = indexPointer->left;
                }
                else {
                    indexPointer = indexPointer->right;
                }
            }
            return false;
        }
        int findMinInTree(bstNode* rootNode) {
            if (rootNode == NULL) return INT_MAX;
            if (rootNode->left == NULL) return rootNode->data;
            return findMinInTree(root->left);
        }

        bstNode* remove(bstNode* tempNode, int value){
            if(tempNode == NULL) return tempNode;
            else if (value < tempNode->data) tempNode->left = remove(tempNode->left, value);
            else if (value > tempNode->data) tempNode->right = remove(tempNode->right, value);
            else {
                // found the element to be deleted.
                // Case 1: Leaf Node
                if (tempNode->left == NULL && tempNode->right == NULL) {
                    delete tempNode;
                    tempNode = NULL;
                }
                // Case 2: Node with single child
                else if (tempNode->left == NULL) { 
                    bstNode* rightSubtree;
                    rightSubtree = tempNode->right;
                    delete tempNode;
                    tempNode = rightSubtree; 
                }
                else if (tempNode->right == NULL) {
                    bstNode* leftSubtree;
                    leftSubtree = tempNode->left;
                    delete tempNode;
                    tempNode = leftSubtree;
                }
                else {
                    int minValue = findMinInTree(tempNode->right);
                    tempNode->data = minValue; 
                    tempNode->right = remove(tempNode->right, minValue);
                }
            }
            return tempNode;
        }
        int height(bstNode* node) {
            if(node == NULL) { return -1; }
            if(node->left == NULL && node->right == NULL) { return 0; }
            int leftHeight, rightHeight;
            leftHeight = node->left ? 1 + height(node->left) : height(node->left);
            rightHeight = node->right ? 1 + height(node->right) : height(node->right);
            return max(leftHeight, rightHeight);
        }
        void bfs(bstNode* node) {
            queue<bstNode*> bfsQueue;
            if (node == NULL) {
                cout << "Empty BST." << endl;
                return;
            }
            bfsQueue.push(node);
            bstNode* current;
            while(!bfsQueue.empty()){
                current = bfsQueue.front(); bfsQueue.pop();
                cout << current->data << ", ";
                if (current->left) { bfsQueue.push(current->left); }
                if (current->right) { bfsQueue.push(current->right); }
            }
        }
        void preorder(bstNode* node) {
            if (node == NULL) {
                return;
            }
            cout << node->data << ", "; 
            inorder(node->left);
            inorder(node->right);
        }
        void postorder(bstNode* node) {
            if (node == NULL) {
                return;
            }
            inorder(node->left);
            inorder(node->right);
            cout << node->data << ", "; 
        }
        void inorder(bstNode* node) {
            if (node == NULL) {
                return;
            }
            inorder(node->left);
            cout << node->data << ", "; 
            inorder(node->right);
        }
};
int main(void) {
    BinarySearchTree bst;
    bst.insert(2);
    bst.insert(5);
    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    bst.insert(8);
    bst.insert(10);
    cout << bst.search(10) << endl;
    cout << bst.search(11) << endl;
    bst.insert(11);
    bst.insert(-1);
    bst.insert(-2);
    cout << bst.search(11) << endl;
    cout << bst.search(-1) << endl;
    cout << bst.height(bst.root) << endl;
    bst.bfs(bst.root);
    cout << endl;
    cout << "Inorder: " << endl;
    bst.inorder(bst.root);
    cout << endl;
    cout << "Preorder: " << endl;
    bst.preorder(bst.root);
    cout << endl;
    cout << "Postorder: " << endl;
    bst.postorder(bst.root);
    cout << endl;
    cout << isBST(bst.root, INT_MIN, INT_MAX) << endl;
    bst.root = bst.remove(bst.root, 1);
    bst.inorder(bst.root);
    cout << endl;
    return 0;
}