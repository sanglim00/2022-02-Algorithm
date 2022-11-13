#include <iostream>
using namespace std;

#define MAX 101

int arr[MAX][MAX];

int LCS(string str, string str2, int m, int n) {
    if(m==0 || n==0) return 0;

    if(arr[m][n] < 0) {
        if(str[m-1] == str2[n-1])
            arr[m][n] = LCS(str, str2, m-1, n-1) + 1;
        else {
            int tmp = LCS(str, str2, m-1, n);
            int tmp2 = LCS(str, str2, m, n-1);
            arr[m][n] = max(tmp, tmp2);
        } 
        
    }
    return arr[m][n];
}

int lengthLCS(string str, string str2, int m, int n){
    
    for(int i = 0; i<= m; i++) {
        for(int j = 0; j<=n; j++) {
            arr[i][j] = -1;
        }
    }
    return LCS(str, str2, m, n);
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