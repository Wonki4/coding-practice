#include <iostream>
#include <fstream>
using namespace std;

bool notWall(int x, int y) {
	if (x < 1 || x>100 || y < 1 || y> 100) return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("./input/input_1210.txt");

	for (int test_case = 1; test_case <= 10; test_case++) {
		int table[102][102] = { 0 };
		int len = 0;
		int start = 0;
		int cy = 100;
		int cx = 0;
		cin >> len;

		int dx[] = { -1 ,1,0};
		int dy[] = { 0 ,0, -1};

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> table[i][j];
			}
		}
		for (int i = 1; i <= 100; i++) {
			if (table[100][i] == 2) cx = i;
		}
		//find the way

		int nexty = 0;
		int nextx = 0;
		bool left = false;
		bool right = false;

		for (int move = 1; move <= 300; move++) {
			if (cy == 1) break;

			for (int i = 0; i < 3; i++) {
				nexty = cy + dy[i];
				nextx = cx + dx[i];
				if (notWall(nextx, nexty) && table[nexty][nextx] == 1) {
					if(i == 0 && !right) {
						cx = nextx;
						left = true;
						break;
					}
					if(i == 1 && !left) {
						cx = nextx;
						right = true;
						break;
					}
					if(i == 2) {
						cy = nexty;
						left = false;
						right = false;
						break;
					}
					//cout <<move<<" "<< cx << " " << cy << " "<< i <<"\n";
				}
			}

		}
		start = cx;
		cout << "#" << test_case << " " << start-1 << "\n";
	}
}