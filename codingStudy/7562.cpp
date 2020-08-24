#include <iostream>
#include <queue>
#define MAX 300
using namespace std;
struct node {
    int y, x, cnt;
};
int T, I, a, b;
queue<node> q;
int nightX[] = {1, 2, 2, 1, -1, -2, -2, -1};
int nightY[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool visited[MAX][MAX];

//범위밖을 나갔는지 체크한다.
bool rangeCheck(int y, int x) {
    if(x >= I || x < 0 || y >= I || y < 0) return false;
    else return true;
}
//BFS 알고리즘
int bfs(node * cur, node * next) {
    int final_y = next->y, final_x = next->x;
    q.push({cur->y, cur->x, 0});
    while(!q.empty()) {
        int y= q.front().y;
        int x= q.front().x;
        int cnt = q.front().cnt;
        q.pop();
        //만약에 도착했으면 횟수를 출력한다.
        if(y == final_y && x == final_x) return cnt;
        for(int i = 0; i<8; i++) {
            //큐에 다음 위치를 삽입.
            int next_y = y + nightY[i];
            int next_x = x + nightX[i];
            if(!visited[next_y][next_x] && rangeCheck(next_y, next_x)) {
                visited[next_y][next_x] = true;
                q.push({next_y, next_x, cnt+1});
            }
        }
    }
    return 0;
}


int main(void) {
    cin>>T;
    for(int test_case = 0 ; test_case < T; test_case++) {
        /////////////////////////////////////////////////
        ///////초기화와 인풋받아오기///////////////////////////
        for(int i = 0; i<MAX; i++) {
            for(int j = 0; j<MAX; j++) {
                visited[i][j] = false;
            }
        }
        while(!q.empty()) q.pop();
        cin >>I;
        cin >> a >> b;
        node * cur = new node({a, b, 0});
        cin >> a >> b;
        node * next = new node({a, b, 0});
        /////////////////////////////////////////////////
        //함수동작
        int move = bfs(cur, next);
        free(cur);
        free(next);
        //출력
        cout<<move<<"\n";
    }
}
