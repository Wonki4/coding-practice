#include<iostream>
#include<fstream>
using namespace std;
int T;
int N;
int X[1000], Y[1000];
long long visited[1000];
double E;
long long prim[1000];

long long dist(int a, int b) {
    long long ans;
    ans = (X[a]-X[b])*(X[a]-X[b]) + (Y[a]-Y[b])*(Y[a]-Y[b]);
    return ans;
}

int main(void) {
    ifstream cin;
    cin.open("/Users/wongi/Downloads/input (1).txt");
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        for(int i = 0 ; i<N; i++) {
            cin >> X[i];
        }
        for(int i = 0; i<N; i++) {
            cin >> Y[i];
        }
        cin >> E;
        //INIT
        ////////////////////////////////////////////////
        prim[0] = 0;
        int cnt = 1;
        for(int i = 1; i<N; i++) {
            prim[i] = 2000000;
            visited[i] = false;
        }
        //LOOP
        ////////////////////////////////////////////////
        long long total = 0;
        int cur = 0;
        visited[cur] = true;
        while(cnt < N) {
            for(int i = 0; i<N; i++) {
                if(!visited[i]) {
                    prim[i] = prim[i] < dist(cur, i) ? prim[i] : dist(cur, i);
                }
            }
            long long min = 2000000;
            int idx = 0;
            for(int i = 0; i<N;i++) {
                if(!visited[i]) {
                    if(min > prim[i]) {
                        min = prim[i];
                        idx = i;
                    }

                }
            }
            total += (long long)(min*E);
            cur = idx;
            visited[cur]= true;
            cnt++;
        }
        cout<<"#"<<test_case<<" "<<total<<endl;
    }
}