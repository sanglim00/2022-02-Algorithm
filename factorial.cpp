#include <iostream>
using namespace std;

int factorial(int num) {
    if (num <= 1) return 1;
    int tmp = num * factorial(num-1);
    while(tmp % 10 == 0 ) {
        tmp = tmp/10;
    }
    return tmp % 1000;

}
int main() {
    
    int times, num ;

    cin >> times;
    for(int i = 0; i < times; i++) {
        cin>> num ;
        
        int answer = factorial(num);
        cout << answer << endl;
    }

    return 0;
}
