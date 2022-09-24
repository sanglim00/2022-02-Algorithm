#include <iostream>
using namespace std;

void reverse(string str, int size) {
    if(size <1) cout<< str[0];
    else {
        cout<< str[size];
        reverse(str, size-1);
    }
}

int main() {

    int times;
    cin >> times;

    for(int i = 0; i< times; i++) {
        string str;
        cin >> str;

        reverse(str, str.length()-1);
        cout<<endl;

    }
 
    return 0;
}