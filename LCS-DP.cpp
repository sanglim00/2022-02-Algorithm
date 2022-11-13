#include <iostream>
using namespace std;

#define MAX 101
#define max(a, b) (a > b) ? a : b 

int L[MAX][MAX], S[MAX][MAX];
string C[MAX][MAX];

void lengthLCS(string str, string str2, int m, int n){
    
    for(int i=0; i<=m; i++) L[i][0] = 0;
    for(int i=0; i<=n; i++) L[0][i] = 0;

    for(int i=1; i <= m; i++) {
        for(int j=1; j <= n; j++){
            if(str[i-1] == str2[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            }
            else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
                if(L[i][j] == L[i][j-1]) {
                    S[i][j] = 1;
                }
                else {
                    S[i][j] = 2;
                }
            }
        }
    }
    cout<<L[m][n]<<" ";
    
}

void printLCS(string str, string str2, int m, int n) {
    if(m == 0 || n == 0) return ;

    if(S[m][n] == 0) {
        printLCS(str, str2, m-1, n-1);
        cout<< str[m-1];
    }
    else if(S[m][n] ==1) printLCS(str, str2, m, n-1);
    else  printLCS(str, str2, m-1, n);
}


int main() {

    int times, m, n;
    string str, str2;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> str >> str2;
        m = str.length();
        n = str2.length();
        lengthLCS(str, str2, m, n);   
        printLCS(str, str2, m, n);
        cout<<endl;     
    }
    return 0;
}
