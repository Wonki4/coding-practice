#include <iostream>
using namespace std;
//이문제는 Finite State Machine 문제였다.
//각 스테이트를 0, 1, 2, 3, 4 다섯개를 놓고
//Acception State는 4로 놓고 유한상태기를 제작했다.
//유한상태기는 while문안에 구현했다.
bool checkNum(int num) {
    int curState = 0;
    int numArr[7] = {0};
    int cnt = 0;
    //숫자를 Token으로 분할한다.
    while(1) {
        numArr[cnt] = num % 10;
        num /= 10;
        if(num == 0) break;
        cnt++;
    }
    //FSM
    int ptr = cnt;
    while(1) {
        switch (curState) {
            case 0: {
                if(numArr[ptr] == 6) curState = 2;
                else curState = 1;
                break;
            }
            case 1: {
                if(numArr[ptr] == 6) curState = 2;
                else curState = 1;
                break;
            }
            case 2: {
                if(numArr[ptr] == 6) curState = 3;
                else curState = 1;
                break;
            }
            case 3: {
                if(numArr[ptr] == 6) curState = 4;
                else curState = 1;
                break;
            }
        }
        ptr--;
        if(curState == 4) return true;
        if(ptr == -1) return false;
    }
}


int main(void) {
    int N;
    cin>>N;
    int cnt = 0;
    int i = 666;
    //내가 원하는 순서의 종말숫자를 찾을때까지 반복
    while(cnt != N) {
        if(checkNum(i)) cnt++;
        i++;
    }
    //출력
    cout<<i-1<<endl;
}
