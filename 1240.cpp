#include <iostream>
#include <cstring>
//#include <fstream>
using namespace std;
char str[50][101];
int pwd[8][4];

typedef struct point{
    int i, j = 0;
} point;

point * initPoint(int i , int j) {
    point * ptr = (point *)malloc(sizeof(ptr));
    ptr->i = i;
    ptr->j = j;
    return ptr;
}

point * findStart(int row, int col) {
    for(int i = 0; i<row; i++) {
        for(int j = col-1; j>=0; j--) {
            if(str[i][j] == '1') return initPoint(i, j);
        }
    }
    return NULL;
}

int main(void) {
    //ifstream cin;
    //cin.open("/Users/wongi/Downloads/input-2.txt");
    int test_case;
    cin>>test_case;
    for(int c = 1; c<=test_case; c++) {
        memset(str, 0 , 50 * 101);
        memset(pwd, 0, 7*4*sizeof(int));
        int row, col;
        cin>>row>>col;
        for(int i = 0; i< row; i++) {
            cin>>str[i];
        }
        point * start = findStart(row, col);
        int x = start->i, y = start->j;
        int cnt = 0, flag = 1;
        int * ptr = &pwd[0][0];
        for (int i = 0; i<56; i++) {
            int cur = str[x][y-i] - '0';
            if(cur != flag) {
                flag = cur;
                *(ptr++) = cnt;
                cnt = 1;
            }
            else if(cur == flag) cnt++;
        }
        *ptr = cnt;
        int total = 0;
        int other = 0;
        for(int i = 0; i <8; i++) {
            char temp[5] = {0,};
            int value = 0;
            for(int j = 0; j<4; j++) {
                temp[j] = pwd[i][j] + '0';
            }
            if(!strcmp(temp,"1123")) value = 0;
            else if(!strcmp(temp,"1222")) value = 1;
            else if(!strcmp(temp,"2212")) value = 2;
            else if(!strcmp(temp,"1141")) value = 3;
            else if(!strcmp(temp,"2311")) value = 4;
            else if(!strcmp(temp,"1321")) value = 5;
            else if(!strcmp(temp,"4111")) value = 6;
            else if(!strcmp(temp,"2131")) value = 7;
            else if(!strcmp(temp,"3121")) value = 8;
            else if(!strcmp(temp,"2113")) value = 9;
            if(i==0) total+= value;
            else {
                if(i%2==0) total+=value;
                if(i%2==1) total+=value*3;
            }
            other += value;
        }
        if(total%10!=0) cout<<"#"<<c<<" 0\n";
        else cout<<"#"<<c<<" "<<other<<"\n";
    }
}

