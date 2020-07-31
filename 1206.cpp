#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
    ifstream cin;
	cin.open("./input/input_1206.txt");
    for(int test_case = 1; test_case <= 10; test_case++) {
        int arr[1001] = {0};
        int len = 0;
        int left = 0;
        int right = 0;
        cin>>len;
        int total = 0;
        for(int i = 1;i<=len; i++) {
            cin>>arr[i];
        }
        for(int i = 3;i<=len-2;i++) {
            left = arr[i-2] > arr[i-1] ? arr[i-2] : arr[i-1];
            right = arr[i+1] < arr[i+2] ? arr[i+2] : arr[i+1];

            int v_left = arr[i] - left;
            int v_right = arr[i] - right;
            if(v_left>=1 && v_right>=1) {
                if(v_left >= v_right) total += v_right;
                else total+= v_left;
            }
        }
        cout<<"#"<<test_case<<" "<<total<<"\n";

    }

}