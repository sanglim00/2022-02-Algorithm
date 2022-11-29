#include <iostream>
using namespace std;

#define MAX 1000
int DFA[MAX][MAX];

void constructDFA(char p[], char t[], int patlen, int& answer) {
    char check;

    DFA[p[0]][0] = 1;
    for(int x = 0, j = 1; j <= patlen; j++) {
        for(int c = 0; c < 3; c++) {
            if(c == 0) check = 'A';
            else if(c == 1) check = 'B';
            else if(c == 2) check = 'C';

            DFA[check][j] = DFA[check][x];
            if (DFA[check][j] != 0) answer++;
        }
        

        if (j < patlen) {
            if (DFA[p[j]][j] == 0) answer++;
            
            DFA[p[j]][j] = j + 1;
            x = DFA[p[j]][x];
        }
    }
    
}

void KMP(char t[], int patlen, int txtlen, int& answer2) {
    for (int i = 0, j = 0; i < txtlen; i++) {
        j = DFA[t[i]][j];
        if (j == patlen) answer2++;
    }
}

int main(){
    int times;
    string str, str2;
    
    cin>> times;
    for(int i = 0; i<times; i++) {

        cin>> str >> str2;
       
        char strArr[str.length()];
        char strArr2[str2.length()];

        int patlen = str.length();
        int txtlen = str2.length();
 
        // string to char[]
        for (int j = 0; j < str.length(); j++) strArr[j] = str[j];
        for (int j = 0; j < str2.length(); j++) strArr2[j] = str2[j];
        
        for(int j = 0; j<MAX; j++) {
            for(int k = 0; k<MAX; k++) {
                DFA[j][k]= 0;
            }
        }
        
        int answer = 1, answer2 = 0;
        constructDFA(strArr, strArr2, patlen, answer);
        KMP(strArr2, patlen, txtlen, answer2);
        cout << answer << " " << answer2 << endl;
    }

    return 0;
}
