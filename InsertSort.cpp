#include <iostream>
using namespace std;

//直接插入排序
void StraightSort(int* nums, int numsSize) {
    int i, j;
    for (i = 0; i < numsSize; i++) {
        int curr = nums[i];
        for (j = i - 1; j >= 0; j--) {
            if (curr < nums[j]) {
                nums[j+1] = nums[j];
            }
        }
        nums[j+1] = curr;
    }
}

//二分插入排序
void BinarySort(int* nums, int numsSize) {
    int i, j;
    for (i = 0; i < numsSize; i++) {
        int curr = nums[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (curr < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = left + 1;
            }
        } //最后返回的right + 1就是插入的位置

        for (j = i - 1; j >= left; j--) { //后移,注意j的上界
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = curr;
    }
}

//希尔插入排序
void ShellSort(int* nums, int numsSize) {
    int gap, i, j;
	for (gap = numsSize / 2; gap > 0; gap /= 2)
		for (i = gap; i < numsSize; i++) {
			int curr = nums[i];
			for (j = i - gap; j >= 0; j -= gap) {
                if (curr < nums[j]) {
                    nums[j + gap] = nums[j];
                }
            }
			nums[j + gap] = curr;
		}
}

//遍历打印数组
void Print(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        cout << nums[i] << " ";
    }
}

int main() {
    const int numsSize = 3;
    int nums[numsSize] = {3,2,1};

    // StraightSort(nums, numsSize);
    // BinarySort(nums, numsSize);
    ShellSort(nums, numsSize);
    Print(nums, numsSize);
    
    return 0;
}
