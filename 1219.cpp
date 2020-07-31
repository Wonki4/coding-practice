#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int way[2][100] = {0};
bool check[100] = {false};

void dfs(int v) {
    check[v] = true;
    for(int i = 0; i<2; i++) {
        if(!check[way[i][v]])
        dfs(way[i][v]);
    }
}

int main(void) {
    ifstream cin;
	cin.open("./input/input_1219.txt");
    for(int test_case = 1; test_case <= 10; test_case++) {
        memset(check, false, 100*sizeof(bool));
        memset(way, 0, 200*sizeof(int));
        int len;
        int a, b, cur;
        cin>>test_case>>len;
        for(int i = 0; i<len; i++) {
            cin>>a>>b;
            if(way[0][a] == 0) way[0][a] = b;
            else way[1][a] = b;
        }
        dfs(0);
        int flag = 0;
        if(check[99]) flag = 1;
        cout<<"#"<<test_case<<" "<<flag<<"\n";
    }
}

// int main(void) {
//     ifstream cin;
//     cin.open("./input-10.txt");
//     for(int test_case = 1; test_case<=10; test_case++) {
//         stack<int> s;
//         memset(way, 0, 2*100*sizeof(int));
//         memset(check, false, 100*sizeof(bool));
//         int len;
//         int a, b, cur;
//         cin>>test_case>>len;
//         for(int i = 0; i<len; i++) {
//             cin>>a>>b;
//             if(way[0][a] == 0) way[0][a] = b;
//             else way[1][a] = b;
//         }
//         s.push(0);
//         check[0] = true;
//         while(!s.empty()) {
//             cur = s.top();
//             s.pop();
//             for(int i = 0; i<2; i++) {
//                 if(way[i][cur] != 0 && !check[way[i][cur]]) {
//                     check[way[i][cur]] = true;
//                     s.push(cur);
//                     s.push(way[i][cur]);
//                     break;
//                 }
//             }
//         }
//         int flag = 0;
//         if(check[99]) flag = 1;
//         cout<<"#"<<test_case<<" "<<flag<<"\n";
//     }
// }