#include <iostream>
using namespace std;

#define MAX 1000
 
int fail[MAX];

void GetFail(char p[], int n){

    for (int i = 0; i < MAX; i++) {
        fail[i] = 0;
    }

    int j = 0;

    cout<<fail[0]<<" ";
    for(int i = 1; i < n ; i++){
        while(j > 0 && p[i] != p[j])
            j = fail[j-1];
        if(p[i] == p[j]){
            fail[i] = ++j;
        }
        cout<<fail[i]<<" ";
    }
    cout<<endl;
}

int kmp(char s[], char p[], int n, int m){

    GetFail(s, n);

    int cnt = 0;
    int j = 0;

    for(int i = 0 ; i < m ; i++){
        while(j > 0 && p[i] != s[j])
            j = fail[j-1];

        if(p[i] == s[j]){
            if (j == n-1){
                j = fail[j];
                cnt++;
            } else {
                j++;
            }
        }
    }
    return cnt;
}



int main(){

    int times;
    string str, str2;
    
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin>> str >> str2;
       
        char strArr[str.length()];
        char strArr2[str2.length()];
 
        for (int j = 0; j < str.length(); j++) {
            strArr[j] = str[j];
        }
        for (int j = 0; j < str2.length(); j++) {
            strArr2[j] = str2[j];
        }

        int answer = kmp(strArr, strArr2, str.length(), str2.length());
        cout<< answer <<endl;

    }

    return 0;
}