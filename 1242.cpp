#include <iostream>
#include <cstring>
using namespace std;
typedef struct point{
    int i;
    int j;
    int len;
} point;
point * ptrset[300];
char str[2000][501];
int pwd[8][4];
int N, M;
int map[5][4][5] ={0};

point * initPoint(int i , int j, int len) {
    point * ptr = (point *)malloc(sizeof(struct point));
    ptr->i = i;
    ptr->j = j;
    ptr->len = len;
    return ptr;
}

int getHex(char c) {
    if(c>='0' && c<= '9') return c-'0';
    if(c>='A' && c<= 'F') return 10+(c-'A');
    return 0;
}

bool checkStart(int x, int y) {
    if(str[x-1][y] == '0' && str[x+1][y] != '0') return true;
    else return false;
}

int findStart(int row, int col) {
    bool plus_one = false;
    int arr_idx = 0;
    int arr[5] = {0};
    int previous = 0;
    int cngCnt = 0;
    int temp;
    int len = 0;
    
    int cnt = 0;
    bool flag = false;
    int x = 0, y= 0;
    for(int i = 0; i<row-1; i++) {
        for(int j = col-1; j>=10; j--) {
            if(str[i][j] != '0' && !flag) {
                x = i;
                y = j;
                flag = true;
                int value = getHex(str[i][j]);
                int idx = 0;
                plus_one = (value & 1) == 0 ? true : false;
                for(int p = idx; p<4; p++) {
                    temp = (value & 1<<p) > 0 ? 1 : 0;
                    if(previous == temp) arr[arr_idx]++;
                    else {
                        previous = temp;
                        cngCnt++;
                        arr[++arr_idx]+=1;
                    }
                }
            }
            else if(flag && cngCnt<5) {
                int value = getHex(str[i][j]);
                for(int p = 0; p<4 && cngCnt<5; p++) {
                    temp = (value & 1<<p)>0 ? 1 : 0;
                    if(previous == temp) arr[arr_idx]++;
                    else {
                        previous = temp;
                        cngCnt++;
                        arr[++arr_idx]+=1;
                    }
                }
            }
            if(flag && cngCnt >= 5){
                len= arr[1];
                len= len < arr[2] ? len: arr[2];
                len= len < arr[3] ? len :arr[3];
                if (plus_one) len = 14 * len+1;
                else len = 14 * len;
                if(checkStart(x, y)) ptrset[cnt++] = initPoint(x, y, len);
                j = y-len+1;
                cngCnt = 0;
                for(int u = 0; u<5; u++) arr[u] = 0;
                plus_one = false;
                previous = 0;
                arr_idx = 0;
                flag = false;
            }
        }
    }
    
    return cnt;
}

void init(void) {
    memset(pwd, 0, 8*4*sizeof(int));
    map[1][1][2] = 0;
    map[1][2][2] = 1;
    map[2][2][1] = 2;
    map[1][1][4] = 3;
    map[2][3][1] = 4;
    map[1][3][2] = 5;
    map[4][1][1] = 6;
    map[2][1][3] = 7;
    map[3][1][2] = 8;
    map[2][1][1] = 9;
}

void processLine(int row, int col, int len) {
    int flag = 0, cnt = 0, value = 0, temp;
    bool first = true;
    int * ptr = &pwd[0][0];
    
    int divider = len/14;
    for(int i = col; i>col-len; i--) {
        value = getHex(str[row][i]);
        for(int j = 0; j<4; j++) {
            temp = (value & 1<<j)>0 ? 1 : 0;
            if(temp == flag) {
                cnt++;
            }
            else if(temp != flag) {
                if(first) {
                    pwd[7][3] += cnt;
                    flag = 1;
                    cnt = 1;
                    first = false;
                }
                else{
                    flag = temp;
                    *(ptr++) = cnt/divider;
                    cnt = 1;
                }
            }
        }
    }
    *ptr+=cnt;
    if(len%2 == 1)*ptr-=4;
    *ptr/=divider;
}

int getValue(void) {
    int total = 0;
    int other = 0;
    for(int i = 0; i < 8; i++) {
        int value = 0;
        value = map[pwd[i][0]][pwd[i][1]][pwd[i][2]];
        if(i==0) total+= value;
        else {
            if(i%2==0) total+=value;
            if(i%2==1) total+=value*3;
        }
        other += value;
    }
    if(total%10!=0) return 0;
    else return other;


}

int main(void) {
    int test_case;
    cin>>test_case;
    for(int c = 1; c<=test_case; c++) {
        init();
        cin>>N>>M;
        for(int i = 0; i< N; i++) {
            cin>>str[i];
        }
        int num = findStart(N, M);
        int total = 0;
        cout<<"#"<<c<<" ";
        for(int i = 0; i<num; i++) {
            processLine(ptrset[i]->i, ptrset[i]->j, ptrset[i]->len);
            total += getValue();
            free(ptrset[i]);
            ptrset[i]= NULL;
            memset(pwd, 0, 8*4*sizeof(int));
        }

        cout<<total<<"\n";

    }
}


