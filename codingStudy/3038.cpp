#include <iostream>
using namespace std;

typedef struct node{
    struct node * left;
    struct node * right;
    int num;
} node;

node * initNode(int value) {
    node * ptr = (node *)malloc(sizeof(node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->num = value;

    return ptr;
}

node * copyTree(node * origin) {
    if (origin == NULL) return NULL;
    node * ptr = (node *)malloc(sizeof(node));
    ptr->left = copyTree(origin->left);
    ptr->right = copyTree(origin->right);
    ptr->num = origin->num;
    return ptr;
}

void preorder(node * parent) {
    if (parent == NULL) return;
    else {
        cout << parent->num << " ";
        preorder(parent->left);
        preorder(parent->right);
    }
    return;
}
void treeProcess_left(node * root) {
    if (root->left == NULL) {
        root->num = root->num * 2 + 1;
        return;
    }
    else {
        root->num = root->num * 2;
        treeProcess_left(root->left);
        treeProcess_left(root->right);
    }
}
void treeProcess_right(node * root) {
    if (root->left == NULL) {
        root->num = root->num * 2;
        return;
    }
    else {
        root->num = root->num * 2 + 1;
        treeProcess_right(root->left);
        treeProcess_right(root->right);
    }
}

int main(void) {
    int level;
    cin >> level;
    node * root = initNode(1);
    if (level == 1) preorder(root);
    else if (level == 2) {
        root->left = initNode(2);
        root->right = initNode(3);
        preorder(root);
    }
    else {
        root->left = initNode(2);
        root->right = initNode(3);
        for (int l = 3; l <= level; l++) {
            node * temp = initNode(1);
            node * copied = copyTree(root);
            treeProcess_left(root);
            treeProcess_right(copied);
            temp->left = root;
            temp->right = copied;
            root = temp;
        }
        preorder(root);
    }
}
