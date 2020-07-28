#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

bool isWall(int x, int y) {
	if (x < 1 || x>100 || y < 1 || y> 100)  return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("C:\\Users\\qordn\\Downloads\\input (1).txt");

	for (int test_case = 1; test_case <= 10; test_case++) {
		int table[102][102] = { 0 };
		int len = 0;
		cin >> len;

		int dx[] = { 0, 1, 1 ,1};
		int dy[] = { 1, 0, 1 ,-1};

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> table[i][j];
			}
		}
		int max = 0;
		int total = 0;
		for (int i = 1; i <= 100; i++) {
			total = 0;
			for (int j = 1; j <= 100; j++) {
				total += table[i][j];
			}
			max = max > total ? max : total;
		}

		for (int i = 1; i <= 100; i++) {
			total = 0;
			for (int j = 1; j <= 100; j++) {
				total += table[j][i];
			}
			max = max > total ? max : total;
		}
		total = 0;
		int x = 1;
		int y = 1;
		for (int i = 1; i <= 100; i++) {
			total += table[x][y];
			x += dx[2];
			y += dy[2];
		}
		max = max > total ? max : total;
		total = 0;
		x = 1;
		y = 100;
		for (int j = 1; j <= 100; j++) {
			total += table[x][y];
			x += dx[3];
			y += dy[3];
		}
		max = max > total ? max : total;


		cout << "#" << test_case << " " << max << "\n";
	}
}