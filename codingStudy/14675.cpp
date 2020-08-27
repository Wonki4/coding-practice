#include <iostream>
using namespace std;
int tree[100001] ={0};
int N, q;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    int a, b;
    for(int i = 0; i<N-1; i++) {
        cin>>a>>b;
        tree[a]++;
        tree[b]++;
    }
    cin>>q;
    for(int i = 0; i<q; i++) {
        cin>>a;
        if(a == 2) {
            cout<<"yes"<<"\n";
            cin>>a;
        }
        else {
            cin>>a;
            if(tree[a] > 1) cout<<"yes"<<"\n";
            else cout<<"no"<<"\n";
        }
    }
}
