
저작권자 : qordnjsrl13@gmail.com
코드 설명 : boj.kr/1244 APS
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
#include <iostream>
using namespace std;
#define MAX 100
int swit[101];
int student_num[101];
int student_sex[101];
int N, SN;
//남자일 경우 해당하는 배수를 전부 바꿔준다.
void man(int num) {
    int iter = (N)/num;
    for(int i = 1; i <= iter; i++) {
        swit[num * i] = swit[num * i] ^ 1;
    }
}
//여자의 경우 주어진 숫자기준으로 좌우로 한칸씩 이동하면서 같으면 바꾸고 아니면 정지한다.
void woman(int num) {
    int mid = N/2;
    int diff;
    if(num > mid) diff = N - num;
    else diff = num - 1;
    
    for(int j = 1; j<=diff ; j++) {
        if(swit[num + j] == swit[num - j]) {
            swit[num + j] = swit[num + j] ^ 1;
            swit[num - j] = swit[num - j] ^ 1;
        }
        else break;
    }
    swit[num] = swit[num] ^ 1;
}
int main(void) {
    //인풋을 받아온다./////////////////////////////////
    cin >> N;
    for(int i = 1; i<= N; i++) {
        cin >> swit[i];
    }
    cin>> SN;
    for(int i = 1; i <= SN; i++) {
        cin >> student_sex[i] >> student_num[i];
    }
    ////////////////////////////////////////////////
    //학생들을 순차적으로 이동하면서 계산을 수행한다.
    for(int i = 1; i <= SN; i++) {
        if(student_sex[i] == 1) man(student_num[i]);
        else if(student_sex[i] == 2) woman(student_num[i]);
    }
    //20개씩 나누기 위한 도는 횟수와 나머지를 계산한다.
    int iter = N / 20;
    int other = N % 20;
    //20개 이상일때 출력하는경우
    if (iter >= 1) {
        for(int i = 0; i < iter; i++) {
            for(int j = 1; j <= 20; j++) {
                cout<<swit[j + (i * 20)] <<" ";
            }
            cout<<"\n";
        }
        for(int i = 1; i <= other; i++) {
            cout<<swit[iter * 20 + i] <<" ";
        }
    }
    //20개 미만일때 출력하는경우
    else {
        for(int i = 1; i <= N; i++) {
            cout<<swit[i] <<" ";
        }
    }
}
