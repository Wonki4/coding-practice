#include <iostream>
#include <cstring>
using namespace std;
typedef struct place {
    int d;
    int maxx;
    int minx;
    int maxy;
    int miny;
    int cx;
    int cy;
} place;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0 ,1};

char cmd[501];

int main(void) {
    int test_case = 0;
    cin>>test_case;
    for(int n = 0; n<test_case; n++) {
        place * p = (place *)malloc(sizeof(place));
        memset(p, 0, sizeof(place));
        memset(cmd, 0, 501);
        cin>>cmd;
        int i = 0;
        while(cmd[i] != '\0') {
            if(cmd[i] == 'F' || cmd[i] == 'B') {
                if(cmd[i] == 'F'){
                    p->cy += dy[p->d];
                    p->cx += dx[p->d]; 
                }
                else {
                    p->cy -= dy[p->d];
                    p->cx -= dx[p->d];
                }
                p->maxy = p->maxy > p->cy ? p->maxy : p->cy;
                p->miny = p->miny < p->cy ? p->miny : p->cy;
                p->maxx = p->maxx > p->cx ? p->maxx : p->cx;
                p->minx = p->minx < p->cx ? p->minx : p->cx;
            }
            else if (cmd[i] == 'L') {
                if(p->d-1 <0) p->d = 3;
                else p->d -= 1;
            }
            else if (cmd[i] == 'R') p->d=(p->d+1)%4;
            i++;
        }
        cout<<(p->maxy-p->miny)*(p->maxx-p->minx)<<"\n";
    }
}