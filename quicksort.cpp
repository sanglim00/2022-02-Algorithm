#include <iostream>
using namespace std;

int Hoare(int* arr, int low, int high, int& swapH, int& comparisonH) {
    int i = low - 1;
    int j = high + 1;;

    int pivot = arr[low];

    while (true) {
        do {
            i++;
            comparisonH++;
        }
        while(arr[i] < pivot);

        do {
            j--;
            comparisonH++;
        }
        while(arr[j] > pivot);

        if(i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            swapH++;
        }
        else return j;
    }

}

void quickSortH(int* arr, int low, int high, int& swapH,int& comparisonH) {
    if(low >= high) return;

    int tmp = Hoare(arr, low, high, swapH, comparisonH);
    quickSortH(arr, low, tmp, swapH, comparisonH);
    quickSortH(arr, tmp+1, high, swapH, comparisonH);
}

int Lomuto(int* arr, int low, int high, int& swapL, int& comparisonL) {
    int j = low;
    
    int pivot, pivotPos, tmp;
    pivot = arr[low];
    
    for(int i = low+1; i<= high; i++) {
        comparisonL++;
        if(arr[i] < pivot){ 
            j++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            swapL++;
        }
    }
    pivotPos = j;
    tmp = arr[low];
    arr[low] = arr[pivotPos];
    arr[pivotPos] = tmp;
    swapL++;

    return pivotPos;

}

void quickSortL(int* arr, int low, int high, int& swapL,int& comparisonL) {
    if(low >= high) return;

    int tmp = Lomuto(arr, low, high, swapL, comparisonL);
    quickSortL(arr, low, tmp-1, swapL, comparisonL);
    quickSortL(arr, tmp+1, high, swapL, comparisonL);
}

int main() {

    int times, num, data;
    int swapH , swapL, comparisonH, comparisonL;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> num;
        int *arrH = new int[num];
        int *arrL = new int[num];
        for(int j = 0; j< num; j++) {
            cin>>data;
            arrH[j] = data;
            arrL[j] = data;
        }

        swapH = swapL = comparisonH = comparisonL = 0;

        quickSortH(arrH, 0, num-1, swapH, comparisonH);
        quickSortL(arrL, 0, num-1, swapL, comparisonL);
      
        cout<< swapH <<" "<<swapL <<" "<<comparisonH<<" " <<comparisonL <<endl;

    }

    return 0;
}