#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main(void) {
    ifstream cin;
	cin.open("./input/input_1218.txt");
    for(int test_case = 1; test_case<=10; test_case++) {
        stack<int> s;
        char str[300] = {0,};
        int n;
        cin>>n;
        cin>>str;
        for(int i = 0; i<n; i++) {
            if(str[i]=='(' || str[i]=='[' || str[i]=='{' || str[i]=='<') {
                s.push(str[i]);
            }
            else if(str[i]==')') {
                if(s.top()=='(') s.pop();
                else break;
            }
            else if(str[i]==']') {
                if(s.top()=='[') s.pop();
                else break;
            }
            else if(str[i]=='}') {
                if(s.top()=='{') s.pop();
                else break;
            }
            else if(str[i]=='>') {
                if(s.top()=='<') s.pop();
                else break;
            }
        }
        int flag = 0;
        if(s.empty()) flag = 1;
        cout<<"#"<<test_case<<" "<<flag<<"\n";

    }


}