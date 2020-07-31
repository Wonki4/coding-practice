#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
int len;
vector<int> v[1001];
int check[1001];
bool visited[1001];
int order_num;
int order[1001];
int child_count[1001];
vector<int> mother;

void dfs(int node) {
    if(!visited[node] && child_count[node] == 0){
        visited[node] = true;
        order[++order_num] = node;
        
        for(int i = 0; i<v[node].size();i++) {
            child_count[v[node][i]]--;
        }
        for(int i = 0; i<v[node].size();i++) {
            dfs(v[node][i]);
        }

    }
}


int main(void) {
    ifstream cin;
	cin.open("./input/input_1267.txt");

    for(int test_case = 1; test_case<=10; test_case++) {
        int V, E, a, b;
        
        cin>>V>>E;
        order_num = -1;
        for(int i = 0; i<1001;i++) {
            v[i].clear();
        }
        mother.clear();
        memset(check, 0, 1001*sizeof(int));
        memset(visited, false, 1001*sizeof(bool));
        memset(order, 0, 1001*sizeof(int));
        memset(child_count, 0, 1001*sizeof(int));
        for(int i = 0; i<E; i++) {
            cin>>a>>b;
            child_count[a]++;
            check[a] = 1;
            v[b].push_back(a);
        }
        for(int i = 1; i<=V; i++) {
            if(check[i]==0) mother.push_back(i);
        }
        for(int i = 0; i<mother.size(); i++) {
            dfs(mother[i]);
        }
        cout<<"#"<<test_case<<" ";
        for(int i = order_num; i>=0;i--) {
            cout<<order[i]<<" ";
        }
        cout<<"\n";
        cout<<order_num<<V<<"\n";
    }
}


