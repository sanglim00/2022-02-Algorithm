#include <iostream>
using namespace std;


// bubble sort algorithm
void bubbleSort(int num, int* arr) {
    int cntCmpOps = 0; // 비교 연산자 실행 횟수 
    int cntSwaps = 0; // swap 함수 실행 횟수

    for (int i = 0; i < num-1; i++) {
        for (int j = 0; j < num-1-i; j++) {
            cntCmpOps++;
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                cntSwaps++;
            }
            
        } 
    }
    cout << cntCmpOps << ' ' << cntSwaps << ' ';
}

// improved bubble sort algorithm 1
void bubbleSortImproved1(int num, int* arr) {
    int cntCmpOps1 = 0;
    int cntSwaps1 = 0;

    bool swap = false;

    for(int i=0; i< num-1; i++) {
        swap = false;
        for(int j=0; j<num-1-i; j++) {
            cntCmpOps1++;
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swap = true;
                cntSwaps1++;
            }
           
        }
        if(swap == false) break;
    }

     cout << cntCmpOps1 << ' ' << cntSwaps1 << ' ';
}

// improved bubble sort algorithm 2
void bubbleSortImproved2(int num, int* arr) {
    int cntCmpOps2 = 0;
    int cntSwaps2 = 0; 

    int lastSwapPos = num;

    while (lastSwapPos > 0) {
        int swapPos = 0;
        for(int i = 1; i< lastSwapPos; i++) {
            cntCmpOps2++;
            if(arr[i-1] > arr[i]) {
                int tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                swapPos = i;
                cntSwaps2++;
            }
        }
        lastSwapPos = swapPos;
    }

    cout << cntCmpOps2 << ' ' << cntSwaps2 << endl;
}

int main() {

    int times, num;
    cin >> times;

    for (int i = 0; i < times; i++) {
        cin >> num;
        int* arr = new int[num];
        int* arr2 = new int[num];
        int* arr3 = new int[num];

        for(int j=0; j< num; j++) {
            int N ;
            cin >> N;
            arr[j] = N;
            arr2[j] = N;
            arr3[j] = N;
        }

        bubbleSort(num, arr);
        bubbleSortImproved1(num, arr2);
        bubbleSortImproved2(num, arr3);
    }
    return 0;

}
