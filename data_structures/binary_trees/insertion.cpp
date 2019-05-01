#include <iostream>
#include <queue>
using namespace std;

struct treeNode {
    int key;
    treeNode* left;
    treeNode* right;
    treeNode (int value) {
        key = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(treeNode* temp) { 
    if (!temp) 
        return; 
  
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
}

// void inorder_iterative(struct treeNode* temp) {}
int getHeight(treeNode* temp) {
    if(temp == NULL) return 0;
    int lHeight = getHeight(temp->left);
    int rHeight = getHeight(temp->right);
    return max(lHeight, rHeight) + 1;
}
void preorder(treeNode* temp) { 
    if (!temp) 
        return; 
  
    cout << temp->key << " "; 
    preorder(temp->left); 
    preorder(temp->right); 
}

void postorder(treeNode* temp) { 
    if (!temp) 
        return; 
  
    postorder(temp->left); 
    inorder(temp->right); 
    cout << temp->key << " "; 
}

void insert(treeNode* temp, int value) {
    queue<treeNode*> nodes;
    nodes.push(temp);
    while(!nodes.empty()) {
        treeNode* current = nodes.front();
        nodes.pop();
        if(!current->left) {
            current->left = new treeNode(value);
            break;
        } else {
            nodes.push(current->left);
        }
        if(!current->right) {
            current->right = new treeNode(value);
            break;
        } else {
            nodes.push(current->right);
        }
    }
    return;
}

bool isMirror(treeNode* temp1, treeNode* temp2) {
    if(temp1 == NULL && temp2 == NULL) return true;
    if (temp1 && temp2 && (temp1->key == temp2->key)) 
        return isMirror(temp1->left, temp2->right) && 
               isMirror(temp1->right, temp2->left);
    return false; 
}

int main() {
    treeNode* root = new treeNode(5);
    inorder(root);
    cout << endl;
    insert(root, 6);
    inorder(root);
    cout << endl;
    insert(root, 8);
    inorder(root);
    cout << endl;
    insert(root, 7);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << isMirror(root, root) << endl;
    cout << "Height : " << getHeight(root) << endl;
    return 0;
}