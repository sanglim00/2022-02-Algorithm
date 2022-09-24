#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c) {
    string s = " to ";
    
    if (n > 0) {
        hanoi(n-1, a, c, b);
        cout<< a << s << c <<endl;
        hanoi(n-1, b, a, c);
    }
}

int main() {

    int times, num;
    cin>> times;

    for(int i = 0; i< times; i++) {
        cin >> num;
        hanoi(num, 1, 2, 3);
    }

    return 0;
}