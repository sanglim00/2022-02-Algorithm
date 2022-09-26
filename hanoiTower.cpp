#include <iostream>
using namespace std;

void push(int *arr, int &idx, int val) {
    if(sizeof(arr) != idx+1) {
        arr[idx] = val;
        cout<< arr[idx] <<' ';
        idx++;
    }
    else cout<< val <<' ';
    
}
void pop(int *arr, int &idx) {
    if(idx == 0) cout<< 0 <<' ';
    else if(idx ==1) cout<< arr[idx--]<<' ';
    else {
        idx--;
        arr[idx] = 0;
        cout<<arr[idx-1]<<' ';
    }
}


void hanoi(int num, int a, int b, int c, int* arr, int &idx) {

    if (num > 0) {
        hanoi(num-1, a, c, b, arr, idx);
        if(c == 3) push(arr, idx, num);
        else if(a == 3) pop(arr, idx);
        hanoi(num-1, b, a, c, arr, idx);
    }

}

int main() {

    int times, num;
    cin>> times;

    for(int i = 0; i< times; i++) {
        cin >> num;
        int idx = 0;
        int* arr = new int[num];
        hanoi(num, 1, 2, 3, arr, idx);
        cout<< endl;
    }

    return 0;
}
