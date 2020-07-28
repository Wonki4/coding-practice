#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("C:\\Users\\qordn\\Downloads\\input.txt");

	for (int test_case = 1; test_case <= 10; test_case++) {
		int table[102][102] = { 0 };
		int len = 0;
		cin >> len;

		int dx[] = { 0,-1,1 };

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> table[i][j];
			}
		}
		for (int move = 1; move <= 100; move++) {
			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= 100; j++) {
					int dir = table[i][j];
					if (dir != 0 && table[i + dx[dir]][j] == 0) {
						table[i][j] = 0;
						table[i + dx[dir]][j] = dir;
					}
				}
			}
		}
		int cnt = 0;
		for (int j = 1; j <= 100; j++) {
			for (int i = 1; i <= 100; i++) {
				int dir = table[i][j];
				if (dir != 0) {
					cnt += 1;
					do {
						i += 1;
					} while (table[i][j] != 0);

				}
			}
		}
		cout <<"#"<<test_case<<" "<< cnt << "\n";
	}

}