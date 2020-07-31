#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
    ifstream cin;
	cin.open("./input/input_1208.txt");

    for (int test_case = 1; test_case<=10; test_case++){
        int dumpNum = 0;
        int col = 101;
        int arr[101] = {0};
        int valueArr[101] = {0};
        int min = 0;
        int max = 0;

        cin>>dumpNum;


        for(int i = 1;i<col; i++) {
            cin>>arr[i];
            int value = arr[i];
            min = min < value ? min : value;
            max = max > value ? max : value;
            valueArr[value] += 1;
        }
        int repeat = 0;
        while(repeat < dumpNum) {
            if (max - min <= 1){
                break;
            }
            else if (valueArr[max] <= 0) {
                max -= 1;
                continue;
            }
            else if (valueArr[min] <= 0) {
                min += 1;
                continue;
            }
            else{
                valueArr[max] -= 1;
                valueArr[min] -= 1;
                valueArr[max-1] += 1;
                valueArr[min+1] +=1;
                repeat += 1;
            }
        }
        if(valueArr[max] <= 0) max -= 1;
        if(valueArr[min] <= 0) min += 1;
        cout<<"#"<<test_case<<" " <<max - min<<"\n";
    }

}
