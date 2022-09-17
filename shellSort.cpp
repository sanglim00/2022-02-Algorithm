#include <iostream>
using namespace std;

void shellSort(int num, int* arr) {
    int cntCmpOps = 0; // 비교 연산자 실행 횟수 
    int cntSwaps = 0; // swap 함수 실행 횟수

    int shrinkRatio = 2;
    int gap = num / shrinkRatio;
    int i, j;
	
    while (gap > 0){
		for (i = gap; i < num; i++) {
			int tmp = arr[i];
			for (j = i; j >= gap; j -= gap){
                cntCmpOps++;
                if (arr[j - gap] > tmp){
                    arr[j] = arr[j - gap];
                    cntSwaps++;     
                } 
                else break;
            }
			arr[j] = tmp;
		}
        gap /= shrinkRatio;
    }

    cout<< cntCmpOps << ' ' << cntSwaps << endl;
}

int main() {

    int times, num;
    cin >> times;

    for(int i=0; i< times; i++) {
        cin>> num;

        int* arr = new int[num];
        for(int j= 0; j<num; j++) {
            int N;
            cin>> N;
            arr[j] = N;
        }

        shellSort(num, arr);
    }
    return 0;
}