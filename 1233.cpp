#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int tree[1001][2];
char value[1001][10];
stack<float> s;
int n;
char operd[1001][10];

void postorder(int v) {
	if (v != 0) {
		postorder(tree[v][0]);
		postorder(tree[v][1]);
		strcpy(operd[n++], value[v]);
	}
}
void postCal(int num) {
	int flag = 1;
	for (int i = 0; i < num; i++) {
		int temp = atoi(operd[i]);
		if (temp != 0) {
			s.push((float)temp);
		}
		else {
			float a, b;
			if (!s.empty()) {
				a = s.top();
				s.pop();
			}
			else {
				flag = 0;
				break;
			}
			if (!s.empty()) {
				b = s.top();
				s.pop();
			}
			else {
				flag = 0;
				break;
			}
			if (operd[i][0] == '+') s.push(a + b);
			else if (operd[i][0] == '-') s.push(b - a);
			else if (operd[i][0] == '*') s.push(a * b);
			else if (operd[i][0] == '/') s.push(b / a);
		}
	}
	int cnt = 0;
	while (!s.empty()) {
		s.pop();
		cnt++;
	}
	if (cnt > 1) flag = 0;
	cout << flag << "\n";
}

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++) {
		n = 0;
		memset(operd, 0, 1001 * 10);
		memset(value, 0, 1001 * sizeof(value[0]));
		memset(tree, 0, 1001*2 * sizeof(int));

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
				else if (j == 1) strcpy(value[node] , result);
				else if (j == 2) tree[node][0] = atoi(result);
				else if (j == 3) tree[node][1] = atoi(result);
				result = strtok(NULL, " ");
			}
		}
		cout << "#" << test_case << " ";
		postorder(1);
		postCal(nodeNum);
		
	}
}