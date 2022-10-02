#include <iostream>
using namespace std;

void mul(int fibo[2][2], int matrix[2][2]){
    int leftTop, rightTop, leftBottom, rightBottom;

    leftTop =  fibo[0][0] * matrix[0][0] + fibo[0][1] * matrix[1][0];
    rightTop =  fibo[0][0] * matrix[0][1] + fibo[0][1] * matrix[1][1];
    leftBottom =  fibo[1][0] * matrix[0][0] + fibo[1][1] * matrix[1][0];
    rightBottom =  fibo[1][0] * matrix[0][1] + fibo[1][1] * matrix[1][1];

    fibo[0][0] = leftTop % 1000;
    fibo[0][1] = rightTop % 1000;
    fibo[1][0] = leftBottom % 1000;
    fibo[1][1] = rightBottom % 1000;
};

void pow(int fibo[2][2], int num){
    int matrix[2][2] = {{1, 1}, {1, 0}};
    
    if (num > 1) {
        pow(fibo, num/2);
        mul(fibo, fibo);

        if (num % 2 != 0) mul(fibo, matrix);
    }
};

int fastFibonacci(int num) {
    int fibo[2][2] = {{1, 1}, {1, 0}};

    if (num <= 1) return num;
    pow(fibo, num-1);

    return fibo[0][0];
}

int main() {

    int times, num;

    cin >> times;
    for(int i = 0; i< times; i++) {
        cin >> num;
        int answer = fastFibonacci(num);
        cout<< answer<< endl;
    }

    return 0;
}
