#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 8
char board[SIZE][SIZE+1];
int cnt = 0;

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

int main(void) {
    ifstream cin;
	cin.open("./input/input_1215.txt");
    for(int test_case = 1; test_case<=10; test_case++) {
        memset(board, 0, SIZE*(SIZE+1));
        cnt = 0;
        int len = 0;
        cin>>len;
        for(int i =0; i<SIZE; i++) {
            cin>>board[i];
        }
        for(int i =0; i<SIZE; i++) {
            for(int j = 0; j<SIZE-len+1; j++) {
                if(felindrome(i, j, len,0)) cnt++;
            }
        }
        for(int i =0; i<SIZE; i++) {
            for(int j = 0; j<SIZE-len+1; j++) {
                if(felindrome(j, i, len,1)) cnt++;
            }
        }

        cout<<"#"<<test_case<<" "<<cnt<<"\n";
    }
}