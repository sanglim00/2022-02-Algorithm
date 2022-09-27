#include <iostream>
using namespace std;

int computingPowers(int a, int n) {

    if (n == 0) return 1;
    else if(n % 2 ==1) {
        int y = computingPowers(a, (n-1)/2)%1000;
        return a * y * y;
    }
    else {
        int y = computingPowers(a, n-1)%1000 ;
        return a * y;
    }
}

int main() {

    int times, a, n;
    cin >> times;

    for(int i =0; i<times; i++) {
        cin >> a >> n ;
        int answer = computingPowers(a, n);
        cout<< answer%1000 << endl;
    }

    return 0;
}