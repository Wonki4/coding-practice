#include <iostream>
using namespace std;
//각각 연결해야하는 포트번호를 담아두고있다.
int port[40001] = {0};
//minset[i]가 의미하는 것은 i개만큼 반도체가 연결되어있을때, 마지막수의 최소값을 저장해야한다.
int minset[40001] ={0};
//처음에 순열을 이용한 완전탐색으로 구현하려고했는데, 시간초과가 나서 다른 방법을 생각해보다가
//백트래킹을 이용해서 시간초과가 나길래 40000번에 대한 연산을 해보았더니
//완탐의 경우 2^N 알고리즘이므로 2초는 턱없이 부족했다.
//DP를 이용해서도 풀어보려고했지만 n^2의 알고리즘이므로 16억이 나오길래 10초는 필요했다.
//그래서 결국 사용한 이진탐색을 이용한 알고리즘이다.
/*https://shoark7.github.io/programming/algorithm/3-LIS-algorithms 이 사이트를 참고했다.*/

//이진탐색의 경우, 각 수가 동일한 경우가 없으므로 좀더 간단해진다.
void binarySearch(int start, int end, int key) {
    if(start == end) {
        if(minset[start] > key) {
            minset[start] = key;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    if(key > minset[mid]) binarySearch(mid+1, end, key);
    else if(key < minset[mid]) binarySearch(start, mid, key);
}
    

int main(void) {
    int N;
    cin >> N;
    
    for(int i = 1; i<=N; i++) {
        cin>>port[i];
        minset[i] =50000;
    }
    int count = 0;
    for(int i = 1; i<=N; i++) {
        //내가 지금 가지고있는수가 수열의 길이를 증가시킬때
        if(minset[count] < port[i]) {
            minset[count+1] = port[i];
            count++;
        }
        //내가 가지고 있는수가 수열의 길이를 증가 시키지못함
        //최장 수열보다 작은 길이의 수열들을 최신화 시켜줘야한다.
        //가장 작은 숫자들을 이용한 수열들이 minset에 저장된다.
        else {
            binarySearch(1, count, port[i]);
        }
    }
    cout<<count<<endl;
}
