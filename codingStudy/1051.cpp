#include <iostream>
#include <cstring>
using namespace std;
int rectangle[51][51] = {0};
int N, M;

bool findSquare(int len) {
	for (int i = 0; i < N-len; i++) {
		for (int j = 0; j < M-len; j++) {
			if (rectangle[i][j] == rectangle[i][j + len] && \
				rectangle[i][j + len] == rectangle[i + len][j] && \
				rectangle[i + len][j] == rectangle[i + len][j + len]) {
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	cin >> N >> M;
	int maxlen = 0;
	int max = N < M ? N : M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &rectangle[i][j]);
		}
	}
	for (int len = 1; len < max; len++) {
		if (findSquare(len)) maxlen = len;
	}
	maxlen++;
	cout << maxlen * maxlen << "\n";
}