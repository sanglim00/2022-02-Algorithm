#include <iostream>
using namespace std;

void insertionSort(int num, int* arr) {
    int cntCmpOps = 0; // 비교 연산자 실행 횟수 
    int cntSwaps = 0; // swap 함수 실행 횟수

    int i = 1, j, tmp;

    while(i < num){
        j = i;
        while( j > 0 ) {
            cntCmpOps++;
            if(arr[j-1] > arr[j]) {
                tmp = arr[j];
                arr[j] = arr[j-1];
                cntSwaps++;
            }
            else break;
            arr[j-1] = tmp;
            j--;
        }
        i++;
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
        insertionSort(num, arr);
      
    }
    return 0;
}