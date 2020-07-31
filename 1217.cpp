#include <iostream>
#include <fstream>
using namespace std;

int power(int a, int p ) {
    if(p == 0) return 1;
    return a * power(a, p-1);
}

int main(void) {
    ifstream cin;
	cin.open("./input/input_1217.txt");
    for(int test_case = 1; test_case <= 10; test_case++) {
        cin>>test_case;
        int a, p, value;
        cin>>a>>p;

        value = power(a,p);
        cout<<"#"<<test_case<<" "<<value<<"\n";
    }
}