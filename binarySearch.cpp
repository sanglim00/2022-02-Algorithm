#include <iostream>
using namespace std;

int binarySearch (int* arr, int left, int right, int value) {
    
    if(left > right) return -1;
    else {
        int mid = (left + right) / 2;
        int tmp;

        if(arr[mid] == value) return mid;
        else if(arr[mid] > value) {
            tmp = binarySearch(arr, left, mid-1, value);
            return tmp;
        }
        else {
            tmp = binarySearch(arr, mid+1, right, value);
            return tmp;
        }
    }
}

int main() {
    int times, n, k;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> n >> k;
        int* arr = new int[n];
        for(int j = 0; j< n; j++) {
            int data;
            cin>> data;
            arr[j] = data;
        }
        int answer = binarySearch(arr, 0, n-1, k);
        cout<<answer <<endl;
    }
}