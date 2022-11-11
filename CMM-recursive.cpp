#include <iostream>
using namespace std;

#define MAX 10

int CMM(int* arr, int i, int j) {
    if(i == j) return 0;

    int min = 2147483647; //일단 제일 큰 값 넣기
    int count = 0;

    int k = i;

    while(k < j) {
        int a = CMM(arr, i, k);
        int b = CMM(arr, k+1, j);
        int c = arr[i-1] * arr[k] * arr[j];

        count = a + b + c;

        if(count < min) min = count;
        k++;
    }

    return min;
}

int main() {

    int times, num, data;

    cin>> times;
    for(int i = 0; i< times; i++) {
        cin>> num;
        int arr[MAX];

        for(int j = 0; j<= num; j++) {
            cin >> data;
            arr[j] = data;
        }

        int answer = CMM(arr, 1, num);
        cout<<answer<<endl;
    }

    return 0;
}