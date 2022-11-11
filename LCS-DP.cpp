
#include <iostream>
using namespace std;

#define MAX 100

int L[MAX][MAX], S[MAX][MAX];

int lengthLCS(string str, string str2, int m, int n){
    
    for(int i=0; i<=m; i++) L[i][0] = 0;
    for(int i=0; i<=n; i++) L[0][i] = 0;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++){
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
    return L[m][n];
}


int main() {

    int times;
    string str, str2;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> str>>str2;
        int answer = lengthLCS(str, str2, str.length(), str2.length());
        cout<<answer<<endl;
        
    }
    return 0;
}