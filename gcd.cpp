#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int r;

    if( a == 0) return b;
    else if(b == 0) return a;
    else {
        do {
            r = a % b;
            a = b;
            b = r;
        }
        while( r!=0 );
        return a;
    }

}

int main() {
    int times, a, b;

    cin >> times;
    for(int i = 0; i< times; i++) {
        cin>> a>> b;
        int answer = gcd(a, b);

        cout<< answer << endl;
    }

    return 0;
}