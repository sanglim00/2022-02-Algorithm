#include <iostream>
using namespace std;

int crossCenter (int* arr, int left, int mid, int right) {
    int thisSum = 0, leftSum = 0, rightSum = 0 ; //0으로 초기화

	for (int i = mid; i >= left; i--) {
		thisSum = thisSum + arr[i];
		if (thisSum > leftSum) leftSum = thisSum;
	}

	thisSum = 0;

	for (int i = mid+1; i <= right; i++) {
		thisSum = thisSum + arr[i];
		if (thisSum > rightSum) rightSum = thisSum;
	}

    return leftSum + rightSum;
}

int maxSubsequenceSum(int *arr, int left, int right) {

    if(left == right) return arr[left];

    int mid = (left + right) / 2;

    int leftSum = maxSubsequenceSum(arr, left, mid);
    int rightSum = maxSubsequenceSum(arr, mid+1, right);
    int crossSum = crossCenter(arr, left, mid, right);

    int maxCheck = max(leftSum, rightSum); //왼, 오 크기 비교
    return max(maxCheck, crossSum); // 위의 값과 교차되는 부분 비교
}

int main() {
    int times, num, data;

    cin >> times;
    for(int i = 0; i< times; i++) {
        cin>> num;
        int* arr = new int[num];
        for(int j = 0; j < num; j++) {
            cin>> data;
            arr[j] = data;
        }
        int answer = maxSubsequenceSum(arr, 0, num-1);
        cout<< answer <<endl;
    }

    return 0;
}
