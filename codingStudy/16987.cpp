#include <iostream>
using namespace std;
int num;
int max_value;
int egg[8][2];

void breakEgg(int egg_num, int broken, int broken_num){
	bool flag = false;
	int temp = broken_num;
	if (egg_num == num) {
		return;
	}
	if (egg[egg_num][0] > 0 && egg[broken][0] > 0) {
		flag = true;
		egg[egg_num][0] -= egg[broken][1];
		egg[broken][0] -= egg[egg_num][1];
		if (egg[egg_num][0] <= 0) temp++;
		if (egg[broken][0] <= 0) temp++;
	}
	for (int i = 0; i < num; i++) {
		if (i != egg_num + 1) breakEgg(egg_num + 1, i, temp);
	}
	if (flag) {
		egg[egg_num][0] += egg[broken][1];
		egg[broken][0] += egg[egg_num][1];
	}
	max_value = max_value > temp ? max_value : temp;
	return;
}



int main()
{
	max_value = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> egg[i][0] >> egg[i][1];
	}
	for (int i = 1; i < num; i++) {
		if(egg[0][0] > 0 && egg[i][0] > 0)breakEgg(0, i, 0);
	}
	cout << max_value << "\n";
}