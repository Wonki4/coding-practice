#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
char str[200];
char post[200];
map<char, pair<int, int> > m;
void makePost(void) {
    int i = 0;
    int p = 0;
    stack<char> s;
    while(str[i]!='\0') {
        if(str[i]>='0'&&str[i]<='9') post[p++] = str[i];
        else if(str[i]=='(') s.push('(');
        else if(str[i]==')') {
            while(s.top() != '(') {
                post[p++] = s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i]=='*') {
            while(!s.empty() && m[s.top()].first >= m[str[i]].second) {
                post[p++] = s.top();
                s.pop();
            }
            s.push('*');
        }
        else if(str[i]=='+') {
            while(!s.empty() && m[s.top()].first >= m[str[i]].second) {
                post[p++] = s.top();
                s.pop();
            }
            s.push('+');
        }
        i++;
    }
}
int postCal(void) {
    int i = 0;
    int v1, v2;
    stack<int> s;
    while(post[i]!='\0') {
        if(post[i]>='0'&&post[i]<='9') s.push(post[i]-'0');
        else if(post[i]=='*') {
            v2 = s.top();
            s.pop();
            v1 = s.top();
            s.pop();
            s.push(v1 * v2);
        }
        else if(post[i]=='+') {
            v2 = s.top();
            s.pop();
            v1 = s.top();
            s.pop();
            s.push(v1 + v2);
        }
        i++;

    }
    return s.top();
}


int main(void) {
    ifstream cin;
    cin.open("/Users/wongi/Downloads/input-12.txt");
    m.insert(make_pair('(',make_pair(0, 3)));
    m.insert(make_pair('*',make_pair(2, 2)));
    m.insert(make_pair('+',make_pair(1, 1)));
    for(int test_case = 1; test_case<=10; test_case++) {
        int len = 0;
        memset(str, 0, 200);
        memset(post, 0, 200);
        cin>>len;
        cin>>str;
        makePost();
        cout<<"#"<<test_case<<" "<<postCal()<<"\n";
    }
}
