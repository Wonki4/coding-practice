#include <fstream>
#include <iostream>
using namespace std;
#define MAX_VALUE 8
int q[MAX_VALUE+1];
int front;
int rear;
int offset[5] = {1,2,3,4,5};


bool queEmpty(void) {
    if(front == rear) return true;
    else return false;
}
bool queFull(void) {
    if(front == (rear+1)%(MAX_VALUE+1)) return true;
    else return false;
}

void user_enque(int value) {
    if(!queFull()) {
        rear = (rear+1)%(MAX_VALUE+1);
        q[rear] = value;
    }
}
int user_deque(void) {
    if(!queEmpty()) {
        front = (front+1)%(MAX_VALUE+1);
        return q[front];
    }
}


int main(void) {
    ifstream cin;
    cin.open("./input/input_1225.txt"); 
    for(int test_case = 1; test_case<=10; test_case++) {
        front = 0;
        rear = 0;
        int value = 0;
        cin>>test_case;
        for(int i = 1; i<MAX_VALUE+1; i++) {
            cin>>value;
            user_enque(value);
        }
        int i = 0;
        while(1) {
            value = user_deque();
            value -= offset[i];
            if(value<=0) {
                user_enque(0);
                break;
            } 
            else {
                user_enque(value);
            }
            i = (i+1)%5;
        }
        cout<<"#"<<test_case<<" ";
        while(!queEmpty()) {
            cout<<user_deque()<<" ";
        }
        cout<<"\n";
    }
}