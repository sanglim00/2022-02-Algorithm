#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c) {
    string s = " to ";
    string s2 = ", moving tower is :  ";

    int nowTower, checkTower ;

    if (n > 0) {
        hanoi(n-1, a, c, b);
        nowTower = n;
        if(c == 3) checkTower = nowTower;
        else checkTower = 0;
        cout<< a << s << c << s2 << nowTower <<endl;
        cout << checkTower << endl;
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
