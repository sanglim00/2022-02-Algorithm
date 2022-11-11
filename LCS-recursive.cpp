#include <iostream>
using namespace std;

#define MAX 10
#define max(a, b) (a > b) ? a : b 

int S[MAX][MAX];

int lengthLCS(string str, string str2, int m, int n){
    
    if(m == 0 || n == 0) return 0;
    
    if(str[m-1] == str2[n-1])
        return lengthLCS(str, str2, m-1, n-1) + 1;
    else {
        int tmp = lengthLCS(str, str2, m-1, n);
        int tmp2 = lengthLCS(str, str2, m, n-1);

        return max(tmp, tmp2);
    }
}

int main() {

    int times;
    string str, str2;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> str>>str2;

        int answer = lengthLCS(str, str2, str.length(), str2.length());
        cout<< answer <<endl;
    }
    return 0;
}