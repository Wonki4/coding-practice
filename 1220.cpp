#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

bool isWall(int x) {
	if(x <1 || x>100) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("./input/input_1220.txt");

	for (int test_case = 1; test_case <= 10; test_case++) {
		int table[102][102] = { 0 };
		int len = 0;
		cin >> len;

		int dx[] = { 0,1,-1 };

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> table[i][j];
			}
		}

		for (int move = 1; move <= 100; move++) {
			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= 100; j++) {
					int mag = table[i][j];
					if (mag != 0 && table[i + dx[mag]][j] == 0) {
						table[i][j] = 0;
						if(isWall(i+dx[mag])) table[i + dx[mag]][j] = 0;
						else table[i + dx[mag]][j] = mag;
					}
				}
			}
		}
		int cnt = 0;
		for (int j = 1; j <= 100; j++) {
			for (int i = 1; i <= 100; i++) {
				int dir = table[i][j];
				int d = 0;
				if (dir != 0) {
					do {
						i+=1;
					}while(dir== table[i][j]);
					d = table[i][j];
					while(d== table[i+1][j]) {
						i+=1;
					}
					cnt+= 1;
				}
			}
		}

		cout <<"#"<<test_case<<" "<< cnt << "\n";
	}

}