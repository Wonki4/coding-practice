#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>
using namespace std;
#define MAX 30
struct node {
    int z, y, x, cnt;
};
char stair[MAX][MAX][MAX+1];
bool visited[MAX][MAX][MAX];
//동, 서, 남, 북, 상, 하
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {0, 0, 0, 0, -1, 1};
int L, R, C;
queue<node> q;
node * wayStart;
node * wayEnd;

node * findStart(void) {
    for(int i = 0; i<L; i++) {
        for(int j = 0; j<R; j++) {
            for(int k = 0; k<C; k++) {
                if(stair[i][j][k] == 'S') {
                    return new node({i, j, k, 0});
                }
            }
        }
    }
    return NULL;
}
node * findEnd(void) {
    for(int i = 0; i<L; i++) {
        for(int j = 0; j<R; j++) {
            for(int k = 0; k<C; k++) {
                if(stair[i][j][k] == 'E') {
                    return new node({i, j, k, 0});
                }
            }
        }
    }
    return NULL;
}

bool rightWay(int z, int y, int x) {
    if(z >= L || z < 0 || y >= R || y < 0 || x >= C || x < 0) return false;
    else return true;
}


int findWay(int start_z, int start_y, int start_x) {
    while(!q.empty()) q.pop();
    int end_z = wayEnd->z, end_y = wayEnd->y, end_x = wayEnd->x;
    q.push({start_z, start_y, start_x, 0});
    node ptr;
    while(!q.empty()) {
        ptr = q.front();
        int z = ptr.z, y = ptr.y, x = ptr.x, cnt = ptr.cnt;
        q.pop();
        if(end_z == z && end_y == y && end_x == x) {
            return cnt;
        }
        for(int i = 0 ;i<6; i++) {
            int next_z = z + dz[i], next_y = y + dy[i], next_x = x + dx[i];
            if(!visited[next_z][next_y][next_x] && rightWay(next_z, next_y, next_x) && stair[next_z][next_y][next_x] != '#') {
                visited[next_z][next_y][next_x] = true;
                q.push({next_z, next_y, next_x, cnt+1});
            }
        }
    }
    return -1;
}

int main(void) {
    ifstream cin;
    cin.open("./testcase.txt");
    while(1) {
        cin>>L>>R>>C;
        if(L == 0) break;
        if(L == 1 && R == 1 && C == 1) {
            cout << "Trapped!" << endl;
            continue;
        }
        memset(stair, 0, 30*30*30*sizeof(char));
        memset(visited, 0, 30*30*30*sizeof(bool));

        for(int i = 0; i<L; i++) {
            for(int j = 0; j<R; j++) {
                cin>>stair[i][j];
            }
        }
        wayStart = findStart();
        wayEnd = findEnd();
        int cnt = findWay(wayStart->z, wayStart->y, wayStart->x);
        if(cnt != -1) cout << "Escaped in " << cnt<< " minute(s)."<<endl;
        else cout << "Trapped!" << endl;
    }
}
