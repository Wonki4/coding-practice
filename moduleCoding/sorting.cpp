#include <iostream>
#include <random>
using namespace std;
#define MAX 30
#define MAX_VALUE (100)

void bubbleSort(int * arr, int n) {
    int swap = 0;
    for(int i = n; i>1; i--) {
        for(int j = 0; j<i; j++) {
            if(arr[j]>arr[j+1]) {
                swap = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] =swap;
            }
        }
    }
}
//max_value is defined as 1000
void countingSort(int * arr, int * sorted, int n){
    int counting[MAX_VALUE+1] = {0};
    for(int i = 0; i<n; i++) {
        counting[arr[i]]++;
    }
    for(int i = 0; i<MAX_VALUE; i++) {
        counting[i+1] += counting[i];
    }
    cout<<"\n";
    for(int i = 0; i<n; i++) {
        sorted[counting[arr[i]]-1] = arr[i];
        counting[arr[i]]--;
    }
}

int main(void) {
    int arr[MAX] = {0};
    int sorted[MAX] = {0};
    for(int i = 0; i<MAX; i++) {
        arr[i] = rand()%MAX_VALUE;
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    countingSort(arr, sorted,MAX);
    bubbleSort(arr, MAX);
    for(int i = 0; i<MAX; i++) {
        cout<<sorted[i]<<" ";
    }
    cout<<"df"<<"\n";
    for(int i = 0; i<MAX; i++) {
        cout<<arr[i]<<" ";
    }
}
