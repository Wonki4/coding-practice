#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

bool notWall(int x, int y) {
	if (x < 1 || x>100 || y < 1 || y> 100)  return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("C:\\Users\\qordn\\Downloads\\input (3).txt");

	for (int test_case = 1; test_case <= 10; test_case++) {
		int table[102][102] = { 0 };
		int len = 0;
		int start = 0;
		int end = 0;
		
		cin >> len;

		int dx[] = { -1 ,1,0};
		int dy[] = { 0 ,0, -1};

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> table[i][j];
			}
		}
		for (int i = 1; i <= 100; i++) {
			if (table[100][i] == 2) end = i;
		}
		//find the way
		int cy = 100;
		int cx = end;
		int nexty = 0;
		int nextx = 0;
		int previousx = end;
		for (int move = 1; move <= 200; move++) {
			if (cy == 1) break;
			for (int i = 0; i < 1; i++) {
				nextx = cx + dx[i];
				nexty = cy + dy[i];
				if (notWall(nextx, nexty) && table[nexty][nextx] == 1) {
					if ((i == 0 || i == 1) && previousx != nextx) {
						previousx = nextx;
						cx = nextx;
						cy = nexty;
						break;
					}
					if (i == 2) {
						previousx = nextx;
						cx = nextx;
						cy = nexty;
					}
				}
			}

		}
		start = cx;
		cout << "#" << test_case << " " << start << "\n";
	}
}