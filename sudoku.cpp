#include <iostream>
using namespace std;

#define N 4
int sdk[N][N];

bool EmptyCheck(int &row, int &col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (sdk[row][col] == 0) return true;
    return false;
}
//row check
bool RowCheck(int row, int num){
    for (int i = 0; i < N; i++)
        if (sdk[row][i] == num) return true;
    return false;
}
//col check
bool ColumnCheck(int col, int num){ 
    for (int i = 0; i < N; i++)
        if (sdk[i][col] == num) return true;
    return false;
}
// 사각형 체크하기
bool SquareCheck(int row, int col, int num){ 
    int startX, startY;
    int endX, endY;

    if((0<=row && row <2) && (0 <=col && col <2 )){
        startX = 0;
        endX = 2;
        startY = 0;
        endY = 2;
    }
    else if((0<=row && row <2) && (2 <=col && col <4 )){
        startX = 0;
        endX = 2;
        startY = 2;
        endY = 4;
    }
    else if((2<=row && row <4) && (0 <=col && col <2 )){
        startX = 2;
        endX = 4;
        startY = 0;
        endY = 2;
    }
    else {
        startX = 2;
        endX = 4;
        startY = 2;
        endY = 4;
    }

    for (int i = startX; i < endX; i++){
        for (int j = startY; j < endY; j++){
            if (sdk[i][j] == num) return true;
        }
    }
    return false;
}

bool Sudoku(){
    int row, col;

    if (EmptyCheck(row, col) == false) return true; 
    
    for (int i = 1; i <= N; i++){
        if (!RowCheck(row, i) && !ColumnCheck(col, i) && !SquareCheck(row, col, i)){
            sdk[row][col] = i;
            if (Sudoku()) return true;
            sdk[row][col] = 0;
        }
    }
    return false;
}

void PrintSudoku(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << sdk[i][j] <<" ";
        }
        cout << endl;
    }
}

int main() {

    int times, data;

    cin>> times;
    for(int i = 0; i< times; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                cin>> data;
                sdk[j][k] = data;
            }
        }
        Sudoku();
        PrintSudoku();
    }
    return 0;
}