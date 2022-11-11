#include <iostream>
using namespace std;

#define MAX 100


int CMM(int arr[], int num) {
    int** mat = new int*[num];
    int** print = new int*[num];
 
    for (int i = 0; i < num; i++) {
        mat[i] = new int[num];
        print[i] = new int[num];
    }
    for (int i = 1; i < num; i++) mat[i][i] = 0;
 
    for (int diagonal = 1; diagonal < num; diagonal++) {
        for (int j = 1; j < num - diagonal; j++) {
            int k = diagonal + j;

            mat[j][k] = 2147483647;

            for (int L = j; L <= k - 1; L++){
                int sum = mat[j][L] + mat[L + 1][k] + arr[j - 1] * arr[L] * arr[k];
                if (sum < mat[j][k]) {
                    mat[j][k] = sum;
                }
            }
        }
    }

    return mat[1][num - 1];
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
        int answer = CMM(arr, num+1);
        cout<<answer<<endl;
    }

    return 0;
}
