#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
int len;
char str[101];

int main(void) {
    ifstream cin;
    cin.open("/Users/wongi/Downloads/input-13.txt");

    for(int test_case = 1; test_case<=10; test_case++) {
        vector<char> v;
        memset(str, 0, 101);
        cin>>len>>str;
        v.push_back(str[0]);
        int i = 1;
        while(str[i]!='\0') {
            if(!v.empty()) {
                if(v.back() == str[i]) v.pop_back();
                else  v.push_back(str[i]);
            }
            else v.push_back(str[i]);
            i++;
        }
        cout<<"#"<<test_case<<" ";
        for(int i = 0; i<v.size();i++) {
            cout<<v[i];
        }
        cout<<"\n";
        
    }
}

