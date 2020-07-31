#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    ifstream cin;
	cin.open("./input/input_1204.txt");
    int test_case = 0;
    cin>>test_case;
    for(int t = 1; t<=test_case; t++) {
        int n = 0;
        int value = 0;
        int maxi = 0;
        int max = 0;
        int score[101] = {0};
        cin>>n;
        for(int i = 0;i<1000;i++) {
            cin>>value;
            score[value] += 1;
        }
        for(int i = 0; i<101;i++) {
            if( max <= score[i]){
                max = score[i];
                maxi = i;
            }
        }
        cout<<"#"<<n<<" "<<maxi<<"\n";
    }
}