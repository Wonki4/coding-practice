#include <iostream>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
char str[31];
int p;
char post[100];
stack<char> s;
stack<char> s2;
map<char, pair<int, int> > m;

void postOper(char c) {
    if(c>='0' && c<='9') post[p++] = c;
    else if(c =='(') {
        s2.push('(');
    }
    else if(c ==')') {
        while(s2.top() != '(') {
            post[p++] = s2.top();
            s2.pop();
        }
        s2.pop();
    }
    else if(c =='*') {
        while(!s2.empty() && m[s2.top()].first >= m['*'].second) {
            post[p++] = s2.top();
            s2.pop();
        }
        s2.push('*');

    }
    else if(c =='+') {
        while(!s2.empty() && m[s2.top()].first >= m['+'].second) {
            post[p++] = s2.top();
            s2.pop();
        }
        s2.push('+');
    }
}
int postCal(void) {
    int i = 0;
    if(post[i]=='\0') return 0;
    int v1, v2;
    stack<int> s_int;
    while (post[i]!='\0') {
        if(post[i]>='0' && post[i]<='9') {
            s_int.push(post[i]-'0');
        }
        else {
            v2 = s_int.top();
            s_int.pop();
            v1 = s_int.top();
            s_int.pop();
            if(post[i] == '*') s_int.push(v1 * v2);
            else if(post[i] == '+') s_int.push(v1 + v2);
        }
        i++;
    }
    return s_int.top();
}

int main(void) {
    p =0;
    memset(str, 0 , 31);
    memset(post, 0, 100);
    m.insert(make_pair('(',make_pair(0, 3)));
    m.insert(make_pair('*',make_pair(2, 2)));
    m.insert(make_pair('+',make_pair(1, 1)));
    
    cin>>str;
    int first = 0;
    int flag = 0;
    int i = 0;
    while(str[i]!='\0') {
        if(!(str[i] =='(' || str[i]==')' || str[i]=='[' ||str[i]==']')) {
            cout<<0<<"\n";
            return 0;
        }
        i++;
    }
    int len = strlen(str);
    if(len%2 == 1) {
        cout<<0<<"\n";
        return 0;
    }
    i = 0;
    while(str[i]!='\0') {
        if(str[i]=='(') {
            s.push('(');
            if((flag^0)) postOper('+');
            postOper('2');
            postOper('*');
            postOper('(');
            flag = 0;
            first = 0;
        }
        else if(str[i]=='[') {
            s.push('[');
            if((flag^0)) postOper('+');
            postOper('3');
            postOper('*');
            postOper('(');
            flag = 0;
            first = 0;
        }
        else if(str[i]==')') {
            if(!s.empty() && s.top() == '(') {
                flag = 1;
                s.pop();
                if(first == 0) postOper('1');
                postOper(')');
                first++;
            }
        }
        else if(str[i]==']') {
            if(!s.empty() && s.top() == '[') {
                flag = 1;
                s.pop();
                if(first == 0) postOper('1');
                postOper(')');
                first++;
            }
        }
        i++;
    }
    while(!s2.empty()) {
        post[p++] = s2.top();
        s2.pop();
    }
    if(!s.empty()) cout<<0<<"\n";
    else {
        cout<<postCal()<<"\n";
    }

}
