#include <iostream>
using namespace std;

int fibonacci(int num) {
    if(num <= 1) return num;
    else return fibonacci(num-1) + fibonacci(num-2);
}

int main() {

    int times, num;

    cin >> times;
    for(int i = 0; i<times; i++) {
        cin >> num;

        int answer = fibonacci(num);
        cout<< answer <<endl;
    }


    return 0;
}