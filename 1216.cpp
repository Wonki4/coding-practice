#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 100
char board[SIZE][SIZE+1];

bool felindrome(int y, int x, int len, int dir) {
    if(dir==0) {
        for(int i = 0; i<len/2; i++) {
            if(board[y][x+i] != board[y][x-i+len-1]) return false;
        }
        return true;
    }
    else {
        for(int i = 0; i<len/2; i++) {
            if(board[y+i][x] != board[y-i+len-1][x]) return false;
        }
        return true;
    }
}
int findMFelindrome(void) {
    for(int len= 100; len>=1; len--) {
        for(int i = 0; i<SIZE; i++) {
            for(int j =0; j<SIZE-len+1; j++) {
                if(felindrome(i, j, len, 0)) return len;
            }
        }
        for(int i = 0; i<SIZE; i++) {
            for(int j =0; j<SIZE-len+1; j++) {
                if(felindrome(j, i, len, 1)) return len;
            }
        }
    }
    return 1;
}
int main(void) {
    ifstream cin;
    cin.open("./input-7.txt");
    for(int test_case = 1; test_case <= 10; test_case++) {
        memset(board, 0, SIZE*(SIZE+1));
        cin>>test_case;
        for(int i = 0; i<SIZE; i++) {
            cin>>board[i];
        }
        int value = findMFelindrome();

        cout<<"#"<<test_case<<" "<<value<<"\n";
    }
}