#include <iostream>
using namespace std;

#define MAX 101
#define min(a, b) (a > b) ? b : a

int mat[MAX][MAX];

int CMM(int* arr, int i, int j) {
    if (i == j) return 0;
    
    if (mat[i][j] != -1) return mat[i][j];

    mat[i][j] = 2147483647;
    
    for(int k = i ; k < j; k++){
        int tmp = CMM(arr, i, k);
        int tmp2 = CMM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        mat[i][j] = min(mat[i][j], tmp + tmp2);
    }

    return mat[i][j];
}
int CMM_memo(int* arr, int i, int j) {

    for(int a = 0; a <= MAX; a++) {
        for(int b = 0; b <= MAX; b++) {
            mat[a][b] = -1;
        }
    }
    return CMM(arr, i, j);
}

int main(void) {

    int times, num, data;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> num;
        int* arr = new int[num+1];

        for(int j = 0; j<= num; j++) {
            cin >> data;
            arr[j] = data;
        }
    
        int answer = CMM_memo(arr, 1, num);

        cout<<answer<<endl;

       
    }
    return 0;
}