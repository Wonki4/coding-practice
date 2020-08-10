#include <iostream>
#include <queue>
#define MAX 25
using namespace std;
char girl[5][6];
bool visited[MAX];
int total;
int dy[] = {1, -1, 0 ,0};
int dx[] = {0, 0, -1, 1};

bool checkSeven(void) {
    int s_cnt = 0;
    int row, col;
    int a = 0;
    int arr[7] = {};
    for(int i = 0; i<MAX; i++) {
        if(visited[i]) {
            arr[a++] = i;
            row = i/5;
            col = i%5;
            if(girl[row][col] == 'S') s_cnt++;
        }
    }
    queue<int> q;
    q.push(arr[0]);
    bool check[25] = {0};
    while(!q.empty()) {
        int top = q.front();
        check[top] = true;
        q.pop();
        row = top/5;
        col = top%5;
        for(int i = 0; i<4; i++) {
            int next_row = row+dy[i], next_col = col+dx[i];
            if(next_row >4 || next_row<0 || next_col >4 || next_col < 0) continue;
            int x = 5*next_row + next_col;
            for(int j = 0; j<7; j++) {
                if(x == arr[j] && !check[x]) q.push(x);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i<7; i++) {
        if(check[arr[i]]) cnt++;
    }
    if(cnt>=7 && s_cnt>=4) {
        return true;
    }
    else return false;
}


void dfs(int start, int cnt) {
    if(cnt >= 7) {
        if(checkSeven()) {
            total++;
        }
        return;
    }
    for(int i = start; i<MAX; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, cnt+1);
            visited[i] = false;
        }
    }
}

int main(void) {
    total = 0;
    for(int i = 0; i <5; i++) {
        cin>>girl[i];
    }
    dfs(0, 0);
    cout<<total<<endl;
}
