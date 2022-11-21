#include <iostream>
using namespace std;

#define MAX 2001
int arr[MAX];
int cnt; // 카운트 변수

void FixHeap(int root, int k, int num) {
    int vacant = root;
    int largest;
    
    while ((arr[vacant * 2] != 0 && vacant * 2 <= num) || (arr[vacant * 2 + 1] != 0 && vacant * 2 + 1 <= num)){
        if (arr[vacant * 2 + 1] != 0 && vacant * 2 + 1 <= num) {
            if (arr[vacant * 2] > arr[vacant * 2 + 1]) largest = vacant * 2;
            else largest = vacant * 2 + 1;
            cnt+=2;
        }
        else {
            largest = vacant * 2; 
            cnt++;
        }
        if (k < arr[largest]){
            arr[vacant] = arr[largest];
            vacant = largest;
        }
        else break;
    }
    arr[vacant] = k;
}

void HeapSort(int num) {
	for (int i = num / 2 ; i > 0; i--) FixHeap(i, arr[i], num);

	for (int i = num ; i > 1; i--) {
        int tmp = arr[1];
        FixHeap(1, arr[i], i-1);
        arr[i] = tmp;
	}
}

int main() {

    int times, num, data;

    cin >> times;
    for(int i = 0; i<times; i++) {
        cin >> num;
        for(int j = 1; j <= num; j++) {
            cin >> data;
            arr[j] = data;
        }
        cnt = 0;
        HeapSort(num);
        cout<< cnt <<endl;
    }

    return 0;
}