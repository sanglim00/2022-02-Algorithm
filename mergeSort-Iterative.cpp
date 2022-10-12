#include <iostream>
using namespace std;

void merge(int*arr, int low, int mid, int high, int& count) {
    int i, j, k;
    int tmp[1000];

    for(i = low; i <= high; i++) tmp[i] = arr[i];

    i = k = low;
    j = mid + 1;

    while(i <= mid && j <= high) { 
        if(tmp[i] <= tmp[j]) arr[k++] = tmp[i++];
        else arr[k++] = tmp[j++];
        count++;
    }

    while(j <= high) arr[k++] = tmp[j++];
    while(i <= mid) arr[k++] = tmp[i++];
}

void mergeSort(int* arr, int num, int& count) {
    int size = 1;
    int low, mid, high;

    while(size < num) {
        for(int i =0; i<num; i += 2*size) {
            low = i;
            mid = min(low + size - 1, num-1);
            high = min(i + 2 * size -1, num-1);

            merge(arr, low, mid, high, count);
        }
        size *= 2;
    }
}


int main() {

    int times, num, data;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>>num;
        int*arr = new int[num];
        for(int j = 0; j<num; j++) {
            cin>> data;
            arr[j] = data;
        }
        int count  = 0;
        mergeSort(arr, num, count);

        cout<<count<<endl;
    }


    return 0;
}