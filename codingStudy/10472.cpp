#include <iostream>
using namespace std;
//내가 찾아야하는 십자뒤집기
int target[9] = {};
//1번부터 9번까지 버튼들을  1개부터 9개까지 선택한 순열을 저장
int comp[1000000][10] = {};
//순열 알고리즘을 위한 bool배열
bool visited[9] = { false };
//몇개의 순열의 개수가 선택되었는지 확인
int cnt;
//상, 하, 좌, 우, 가운데
int dy[] = {0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, -1, 1};
//버튼을 눌렀을때에 대한 함수
void clickButton(int button, int old, int news) {
    int y = button / 3, x = button % 3;
    int next_y, next_x;
    for(int i = 0; i<10; i++) comp[news][i] = comp[old][i];
    comp[news][9] = comp[news][9]+1;
    for(int i = 0; i<5; i++) {
        next_y = y + dy[i];
        next_x = x + dx[i];

        if(next_y<0 || next_y>2) continue;
        if(next_x<0 || next_x>2) continue;
        if (comp[old][next_y*3 + next_x] == 0) comp[news][next_y*3 + next_x] = 1;
        if (comp[old][next_y*3 + next_x] == 1) comp[news][next_y*3 + next_x] = 0;
    }
}
//버튼을 1개부터 9개까지 선택하는 상태를 모두 저장하는 순열 알고리즘
void makeComp(int idx, int max, int arrNum) {
    if(idx == max) {
        return;
    }
    for(int i = 0; i < max; i++) {
        if(!visited[i]) {
            visited[i] = true;
            cnt++;
            clickButton(i, arrNum, cnt);
            makeComp(i+1, max, cnt);
            visited[i] = false;
        }
    
    }
}

int main(void) {
    //테스트케이스가 50개이므로 저장을 해놓고 문제를 푸는것이 이득
    //먼저 버튼선택들의 순열을 구하고시작한다.
    cnt = 0;
    makeComp(0, 9, 0);
    //테스트케이스 개수를 받아온다.
     int T;
     cin>>T;
     for(int test_case = 0; test_case < T; test_case++) {
         char bup[4] = "";
         //일차원배열에 타겟 십자뒤집기를 저장
         for(int i = 0; i < 3; i++) {
             cin >> bup;
             for(int j = 0; j < 3; j++) {
             if(bup[j] == '*') target[3 * i + j] = 1;
             else target[3 * i + j] = 0;
             }
         }
         int min = 10;
         //저장해놓은 순열들과 타겟십자뒤집기를 비교한다.
         for(int i = 0; i<=cnt; i++) {
             int flag = true;
             
             for(int j = 0; j<9; j++) {
                 if(comp[i][j] != target[j]) flag = false;
             }
             //최솟값을 저장
             if(flag)min = min < comp[i][9] ? min : comp[i][9];
         }
         //최솟값을 출력한다.
         cout<<min<<endl;
     }
}
