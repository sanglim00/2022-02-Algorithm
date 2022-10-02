#include <iostream>
using namespace std;

int *arr;

int fastFibonacci(int num) {

    int k, a, b;
    if(num <= 1) {
        arr[num] = num;
        return num;
    }
    if(arr[num]) return arr[num];

    if(num & 1) k = (num + 1)/2;
    else k = num/2;

    a = fastFibonacci(k) % 1000;
    b = fastFibonacci(k-1) % 1000;

    if(num & 1) arr[num] = (a * a + b * b)%1000;
    else arr[num] = ((2 * b + a)*a)%1000;

    return arr[num] % 1000;
}

int main() {

    int times, num;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin >> num;
        arr = new int[num];
        int answer = fastFibonacci(num);
        cout<< answer<< endl;
        
    }

    return 0;
}