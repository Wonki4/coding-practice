#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int arr[15][15] ={0};
int M, N;
//정사각형내부에 있는 파리의 총 개수를 세어주는 함수
int getArea(int y, int x) {
    int area = 0;
    for(int i = 0; i<M;i++) {
        for(int j = 0; j<M; j++) {
            area+=arr[y+i][x+j];
        }
    }
    return area;
}

int main(void) {
    ifstream cin;
    cin.open("./input.txt");
    int iter;
    cin>>iter;
    //Case만큼 loop를 돈다.
    for(int test_case = 1; test_case<=iter; test_case++) {
        int max = 0;
        int value = 0;
        cin>>N>>M;
        memset(arr, 0, 15*15*sizeof(int));
        for(int i = 0 ;i<N;i++) {
            for(int j = 0; j<N; j++) {
                cin>>arr[i][j];
            }
        }
        //가로 세로 N-M+1까지 첫꼭지점으로 잡고 쭉 돈다.
        for(int i = 0 ;i<N-M+1;i++) {
            for(int j = 0; j<N-M+1; j++) {
                value = getArea(i, j);
                max = max > value ? max : value;
            }
        }
        cout<<"#"<<test_case<<" "<<max<<"\n";
    }
}