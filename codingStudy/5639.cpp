#include <iostream>
using namespace std;
struct node {
    struct node * left;
    struct node * right;
    int value;
};
node * head = new node({NULL, NULL, 0});

void insertNode(int num) {
    if(head-> value == 0) head->value = num;
    else {
        node * ptr = head;
        while(1) {
            if(ptr->value > num) {
                if(ptr->left == NULL) {
                    ptr->left = new node({NULL, NULL, num});
                    break;
                }
                else {
                    ptr = ptr->left;
                    continue;
                } 
            }
            else {
                if(ptr->right == NULL) {
                    ptr->right = new node({NULL, NULL, num});
                    break;
                }
                else {
                    ptr = ptr->right;
                    continue;
                }
            }
        }
    }
} 

void postOrder(node * ptr) {
    if(ptr == NULL) return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout<<ptr->value<<"\n";
}

int main(void) {
    int num = 0;
    while(cin>>num){
        insertNode(num);
    }
    postOrder(head);
}