#include <iostream>
using namespace std;
int tree[50];
int childNum[50] = {0};

int main(void) {

    int N, target;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin>>tree[i];
        if(tree[i] != -1) childNum[tree[i]]++;
    }
    cin>>target;
    int cnt = 0;
    childNum[tree[target]]--;
    for(int i = 0; i <N; i++) {
        //leaf
        int parent = 0;
        if(childNum[i] == 0) {
            if(i == target) continue;
            cnt++;
            parent = tree[i];
            while(parent != -1) {
                if(parent == target) {
                    cnt--;
                    break;
                }
                parent = tree[parent];
            }
        }
        //parent
        else {
            continue;
        }
    }
    cout<<cnt<<endl;
}