#include <iostream>
using namespace std;

#define MAX 100

void merge(int *arr, int low, int mid, int high, int &count) {
    int i, j, k = low;
    int tmp[MAX];

    // tmp에 값 복사
    for(i = low; i <= high; i++) tmp[i] = arr[i];

    i = low;
    j = mid + 1;

    while(i <= mid && j <= high) {
        if(tmp[i] <= tmp[j]) 
            arr[k++] = tmp[i++];
        else 
            arr[k++] = tmp[j++];
        count++;
    }

    // 남은 값들 넣기
    while(j <= high) arr[k++] = tmp[j++];
    while(i <= mid) arr[k++] = tmp[i++];
}

void mergeSort(int *arr, int low, int high, int &count) {

    if(low == high) return ;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid+1, high, count);
    merge(arr, low, mid, high, count);
}

int main() {

    int times, num, data, count;

    cin>> times;
    for(int i = 0;  i< times; i++) {
        cin >> num;
        count = 0;
        int *arr = new int[num];
        for(int j = 0; j< num; j++ ) {
            cin>> data;
            arr[j] = data;
        }

        mergeSort(arr, 0, num-1, count);
        cout<< count<<endl;
    }

    return 0;
}