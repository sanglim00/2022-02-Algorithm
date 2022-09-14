#include <iostream>
using namespace std;


void combSort(int num, int* arr) {
    int cntCmpOps = 0; // 비교 연산자 실행 횟수 
    int cntSwaps = 0; // swap 함수 실행 횟수

    int gap = num;
    float shrink = 1.3;
    bool sorted = false;
   
    while(sorted == false) {
        gap = (int)gap/shrink;
        
        if (gap <= 1){
            gap = 1;
            sorted = true;
        }
        int i = 0;
        
        while(i + gap < num) {
            cntCmpOps++;
            if(arr[i] > arr[i+gap]){
                cntSwaps++;
                int tmp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = tmp;
                sorted= false;
            }
            i++;
        }
    }

    cout<< cntCmpOps << ' ' << cntSwaps << endl;

}

int main() {

    int times, num;
    cin >> times;

    for(int i = 0; i< times; i++) {
        cin>> num ;

        int* arr = new int[num];
        for(int j = 0; j<num; j++) {
            int N;
            cin >> N;
            arr[j] = N;
        }

        combSort(num, arr);

    }

    return 0;
}
