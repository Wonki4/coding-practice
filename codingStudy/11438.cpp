#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
int N, M;
bool visited[MAX];
int dis[MAX] = {0};
int par[MAX][21] = { 0 };
vector<vector<int> > v;

void dfs(int cur) {
    
    for(int i = 0; i< v[cur].size(); i++) {
        if(!visited[v[cur][i]]) {
            visited[v[cur][i]] = true;
            par[v[cur][i]][0] = cur;
            dis[v[cur][i]] = dis[cur]+1;
            dfs(v[cur][i]);
        }
    }
}

void findParents(void) {
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= N; i++) {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    return;
}

int lca(int x, int y) {
    if(dis[x] > dis[y]) {
        int temp = x;
        x = y;
        y = temp;
    }
    for(int i = 20; i >= 0; i--) {
        if(dis[y] - dis[x] >= (1 << i)) {
            y = par[y][i];
        }
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--) {
        if(par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i <MAX; i++) visited[i] = false;
    cin>>N;
    v.resize(N + 1);
    int a, b;
    for(int i = 0; i<N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1] = true;
    dfs(1);
    
    findParents();
    cin>>M;
    for(int i = 0; i< M; i++) {
        cin >> a >> b;
        cout<<lca(a, b)<<"\n";
    }
    
}
