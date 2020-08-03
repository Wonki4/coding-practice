#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> pi(char p[]) {
    int len = strlen(p);
    int j = 0;
    vector<int> pi(len, 0);
    for(int i = 1; i<len; i++) {
        while(j>0 && p[i] != p[j]) j = pi[j-1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}
vector<int> kmp(char s[], char p[], vector<int> pi) {
    int len = strlen(s);
    int p_len = strlen(p);
    vector<int> n;
    int j = 0;
    for(int i = 0; i<len; i++) {
        while(j >0 && s[i] != p [j]){
            j = pi[j-1];
        }
        if(s[i] == p[j]) {
            if(j == p_len-1) {
                n.push_back(i-j);
                j = pi[j];
            }
            else j++;
        }
    }
    return n;

}

int main(void) {
    char t[1000001];
    char p[1000001];
    memset(t, 0,1000001);
    memset(p, 0,1000001);
    cin.getline(t, 1000001);
    cin.getline(p, 1000001);
    
    vector<int> v_pi = pi(p);
    vector<int> ans = kmp(t, p, v_pi);
    cout<<ans.size()<<"\n";
    for(int i = 0; i<ans.size();i++) {
        cout<<ans[i]+1<<" ";
    }
}
