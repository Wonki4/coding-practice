#include <iostream>
using namespace std;
int target[9] = {};
int base[9][9] = {};
int comp[1000][9] = {};
bool visited[9] = { false };
int cnt;

void makeComp(int idx, int max, int arr[]) {
    if(idx == max) {
        return;
    }
    for(int i = idx, i < max i++) {
        if(!visited[i]) {
            visited[i] = true;
            makeComp(i, max);
            cnt++;
            calComp()
            visited[i] = false;
        }
    
    }
}

int main(void) {
    int T;
    cin>>T;
    char[4] bup;

    for(int i = 0; i < 3; i++) {
        cnt = 0;
        cin >> bup;
        for(int j = 0; j < 3; j++) {
            if(bup[j] = '*') target[3 * i + j] = 1;
            else target[3 * i + j] = 0;
        }
    }

}