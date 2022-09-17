#include <iostream>
using namespace std;

void selectionSort(int num, int* arr) {
    int cntCmpOps = 0; // 비교 연산자 실행 횟수 
    int cntSwaps = 0; // swap 함수 실행 횟수

    int i, j, min;

    for(i = 0; i < num-1; i++ ) {
        min = i;
        for(j = i + 1; j < num; j++) {
            cntCmpOps++;
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(i != min) {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
            cntSwaps++;
        }
       
    }
    cout<< cntCmpOps << ' ' << cntSwaps << endl;
}

int main() {

    int times, num;
    cin >> times;

    for(int i=0; i< times; i++) {
        cin>> num;

        int* arr = new int[num];
        for(int j= 0; j<num; j++) {
            int N;
            cin>> N;
            arr[j] = N;
        }
        selectionSort(num, arr);       
    }
    return 0;
}