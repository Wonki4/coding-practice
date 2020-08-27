#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
int T;
int map[MAX][MAX];
int N;
int sx = 0, sy = 0, gx, gy;
bool visited[MAX][MAX];
int di[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool checkRange(int x, int y) {
    if(x < 0 || x>= N || y < 0 || y >= N) return false;
    else return true;
}

int main(void) {
    ifstream cin;
    cin.open("/Users/wongi/Downloads/input (2).txt");
    cin>>T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cin>>N;
        gx = N-1;
        gy = N-1;
        char temp[101];
        for(int i = 0; i<N; i++) {
            cin>>temp;
            for(int j = 0; j<N; j++) {
                map[i][j] = temp[j] - '0';
                visited[i][j] = 0;
                di[i][j] = 90001;
            }
        }
        visited[sy][sx] = true;
        di[sy][sx] = 0;
        
        int cx = sx, cy = sy;
        while(1) {
            for(int i = 0; i<4; i++) {
                int ny = cy + dy[i], nx = cx + dx[i];
                if(checkRange(ny, nx) && !visited[ny][nx]) {
                    di[ny][nx] = di[ny][nx] < (map[ny][nx] + di[cy][cx])? di[ny][nx] : (map[ny][nx] + di[cy][cx]);
                }
            }
            int min = 90001;
            int ix = 0, iy = 0;
            for(int i = 0; i<N; i++) {
                for(int j = 0; j<N; j++) {
                    if(!visited[i][j] && min > di[i][j]) {
                        min = di[i][j];
                        iy = i;
                        ix = j;
                    }
                }
            }
            visited[iy][ix] = true;
            cy = iy;
            cx = ix;
            if(cy == gy && cx == gx) break;
        }
        cout<<"#"<<test_case<<" "<<di[gy][gx]<<endl;
    }
}
