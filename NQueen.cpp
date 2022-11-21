#include <iostream>
using namespace std;
 
#define N 16
int col[N];
bool check;
int num;

void printNQueen() {
    for (int i = 0; i < num; i++) cout << col[i]+1 << " ";
    cout<<endl;
}

int isPromising(int row)  {
    int k = 0;

    while (k < row ) {
        if (col[row] == col[k] || abs(col[row] - col[k]) == row - k)
            return 0;
        k++;
    }
    return 1;
}

void NQueen(int row) {
    int i;
    if(check == false) return ;

    if (isPromising(row)){
        if (row == num-1){
            check = false;
            printNQueen();
        }
        else {
            for (i = 0; i < num; i++) {
                col[row + 1] = i;
                NQueen(row + 1);
            }
        }
    } 
}
 
 
int main() {
    int times;

    cin>> times;
    for(int i = 0; i<times; i++) {
        cin >> num;
        check = true;
        for(int j = 0; j< N; j++) {
            if(check){
                col[0] = j;
                NQueen(0);
            }
        }
    }
    
    return 0;
}