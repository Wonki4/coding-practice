#include <iostream>
#include <cstring>
using namespace std;
int tree[101][2];
char value[101];
 
void inorder(int v) {
    if (v != 0) {
        inorder(tree[v][0]);
        cout << value[v];
        inorder(tree[v][1]);
    }
}
int main()
{
    for (int test_case = 1; test_case <= 10; test_case++) {
        memset(value, 0, 101);
        memset(tree, 0, 101 * 2 * sizeof(int));
        int nodeNum;
        int node;
        char noden[20];
        cin.getline(noden, 20);
        nodeNum = atoi(noden);
        for (int i = 0; i < nodeNum; i++) {
            char temp[20];
            cin.getline(temp, 20);
            char * next_token;
            char * result = strtok(temp, " ");
            for (int j = 0; j < 4 && result != NULL; j++) {
                if (j == 0) node = atoi(result);
                else if (j == 1) value[node] = result[0];
                else if (j == 2) tree[node][0] = atoi(result);
                else if (j == 3) tree[node][1] = atoi(result);
                result = strtok(NULL, " ");
            }
        }
        cout << "#" << test_case << " ";
        inorder(1);
        cout << "\n";
         
    }
}