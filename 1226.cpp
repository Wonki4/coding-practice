#include <fstream>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int m[16][16];
bool visited[16][16];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
queue<pair<int,int> > q;

int main(void) {
    ifstream cin;
    cin.open("./input/input_1226.txt");
    for(int test_case = 1; test_case<=10; test_case++) {
        memset(visited, false, 16*16*sizeof(bool));
        int flag = 0;
        cin>>test_case;
        char v[17];
        for(int i = 0; i < 16; i++) {
            cin>>v;
            for(int j = 0; j<16; j++) {
                m[i][j] = v[j]-'0';
            }
        }
        q.push(make_pair(1,1));
        int x, y = 0;
        while(!q.empty()) {
            visited[q.front().first][q.front().second] = true;
            for(int i = 0; i<4; i++) {
                y = q.front().first + dy[i];
                x = q.front().second + dx[i];
                if(m[y][x] != 1 && !visited[y][x]) q.push(make_pair(y,x));
                if(m[y][x] == 3) {
                    flag = 1;
                }
            }
            q.pop();
        }
        cout<<"#"<<test_case<<" "<<flag<<"\n";

        
    }
}