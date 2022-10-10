#include <iostream>
using namespace std;

int crossCenter (int* arr, int left, int mid, int right) {
    int sum = 0;
	int leftSum = -1;   // 0보다 작은 값으로 초기화 하기
	for (int i = mid; i >= left; i--) {
		sum = sum + arr[i];
		if (sum > leftSum)
			leftSum = sum;
	}
	sum = 0;
	int rightSum = -1;  // 0보다 작은 값으로 초기화 하기
	for (int i = mid; i <= right; i++) {
		sum = sum + arr[i];
		if (sum > rightSum)
			rightSum = sum;
	}

    int maxR = max(leftSum + rightSum - arr[mid], leftSum);
	return max(maxR, rightSum);
}

int maxSubsequenceSum(int *arr, int left, int right) {

    if(left > right) return 0;
    if(left == right) return arr[left];
    int mid = (left + right) / 2;

    int leftSum = maxSubsequenceSum(arr, left, mid - 1);
    int rightSum = maxSubsequenceSum(arr, mid+1, right);
    int LRSum = crossCenter(arr, left, mid, right);

    int maxR = max(leftSum, rightSum);
    return max(maxR, LRSum);
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