#include <iostream>
#include <cstring>
using namespace std;
//각 숫자의 개수를 담아두기위한 배열
int arr[9];

int main(void) {
    memset(arr, 0, 9 * sizeof(int));
    char N[8];
    cin>>N;
    //받아온 숫자의 길이 체크
    int len = strlen(N);
    for(int i = 0; i<len ; i++) {
        //9는 6과 같으므로 같이 넣는다.
        if(N[i] - '0' == 9) arr[6]++;
        else arr[N[i] - '0']++;
    }
    //짝수일때는 나눈 몫만큼, 홀수일때는 나눈 몫 + 1 이다.
    arr[6] = arr[6] / 2 + arr[6] % 2;
    int max = 0;
    for(int i = 0; i<9; i++) {
        //배열에서 최댓값을 찾는다.
        max = max > arr[i] ? max : arr[i];
    }
    //출력
    cout<<max<<endl;
}