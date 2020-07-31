#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int main(void) {
    ifstream cin;
	cin.open("./input/input_1213.txt");
    for(int test_case = 1; test_case <=10; test_case++) {
        int num = 0;
        int ss;
        char str[1000];
        char target[10];
        cin>>ss;
        cin>>target;
        cin>>str;
        for (int i = 0; i<strlen(str); i++) {
            int cnt = 0;
            for(int j = 0; j<strlen(target); j++) {
                if(str[i+j] == target[j]) cnt++;
                else break;
            }
            if(cnt == strlen(target)) num++;
        }
        cout<<'#'<<test_case<<" "<<num<<"\n";
    }
}