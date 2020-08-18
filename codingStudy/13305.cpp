#include <iostream>
using namespace std;
//long long으로 연산해야하므로 long long 으로 선언한다.
long long w[100001];
long long way[100001];
int main(void) {
    int N;
    cin>>N;
    //길의 길이를 받아온다.
    for(int i = 0; i<N-1; i++) {
        cin>>way[i];
    }
    //기름의 가격을 받아온다.
    for(int i = 0; i<N; i++) {
        cin>>w[i];
    }
    //10억보다 큰값으로 min을 초기화한다.
    long long min = 1000000001;
    long long total = 0;
    for(int i = 0; i<N-1; i++) {
        //최소의 기름값과 지금 도착한 도시의 기름값을 비교한다.
        min = min < w[i] ? min : w[i];
        total += (min * way[i]);
    }
    //출력한다.
    cout<<total<<endl;
}
