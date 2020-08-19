#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1000000
int note1[MAX];
int note2[MAX];

//시간초가 2초이기때문에 nlog n의 시간복잡도를 가져야하므로 이진탐색
bool binarySearch(int left, int right, int num) {
    if(left>right) return false;
    int mid = (left + right) / 2;
    if(num == note1[mid]) return true;
    else if (note1[mid] > num) return binarySearch(left,mid-1, num);
    else return binarySearch(mid+1, right, num);
}


int main(void) {
    int T, N, M;
    cin>>T;
    //테스트케이스만큼돈다.
    for(int test_case = 0; test_case < T; test_case++) {
        memset(note1, 0, sizeof(int) * MAX);
        memset(note2, 0, sizeof(int) * MAX);
        cin>>N;
        for(int i = 0 ; i<N; i++) {
            cin >> note1[i];
        }
        cin>>M;
        for(int i = 0; i<M; i++) {
            cin >> note2[i];
        }
        //비교대상을 이진탐색하기위해 소팅한다.
        sort(&note1[0], &note1[N]);

        for(int i = 0; i<M; i++) {
            //하나씩 비교한다.
            cout<<binarySearch(0, N-1, note2[i])<<"\n";
        }
    }
}