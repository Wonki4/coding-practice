#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
bool called[101];
vector<int> v[101];
queue<pair<int, int> > q;

int main(void) {
    ifstream cin;
    cin.open("./input/input_1238.txt");
    for (int test_case = 1; test_case<=10; test_case++) {
        int n, start;
        int sender, receiver, iter;
        memset(called, false, 101*sizeof(bool));
        for(int i = 0; i<101; i++) {
            v[i].clear();
        }
        cin>>n>>start;
        for(int i = 0; i<n/2; i++) {
            cin>>sender>>receiver;
            v[sender].push_back(receiver);
        }
        q.push(make_pair(start, 0));
        int max_sender = start, max_iter = 0;
        while(!q.empty()) {
            sender = q.front().first;
            iter = q.front().second;
            q.pop();
            if(!called[sender]){
                if(iter>max_iter) {
                    max_iter = iter;
                    max_sender = sender;
                }
                else if(iter==max_iter) {
                    max_iter = iter;
                    max_sender = max_sender > sender ? max_sender : sender;
                }
                called[sender] = true;
                if(!v[sender].empty()){
                    for(int i = 0; i<v[sender].size(); i++) {
                        if(!called[v[sender][i]])
                            q.push(make_pair(v[sender][i], iter+1));
                    }
                }
            }
        }
        cout<<"#"<<test_case<<" "<<max_sender<<"\n";
    }
}