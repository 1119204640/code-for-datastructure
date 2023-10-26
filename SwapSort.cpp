#include <iostream>
using namespace std;

//用于两数交换
void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序
void BubbleSort(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        bool isSwap = false; //当一次外层循环中，相邻的元素没有发生交换，就说明数组已经是有序的了，这时可以跳出循环。
        for (int j = 0; j + 1  < numsSize - i; j++) {
            if (nums[j] > nums[j+1]) {
                Swap(&nums[j], &nums[j+1]);
                isSwap = true;
            }
        }
        if (isSwap == false) {
            break;
        }
    }
}

//快速排序的划分
int Partition(int* nums, int low, int high) {
    int privot = nums[low];
    while (low < high) {
        while (low < high && privot <= nums[high]) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && privot >= nums[low]) {
            low++;
        }
        nums[high] = nums[low];
    }

    nums[low] = privot;
    return low;
}

//快速排序算法的递归
void QuickSort(int* nums, int low, int high) {
    if (low < high) {
        int privot = Partition(nums, low, high);
        QuickSort(nums, low, privot - 1);
        QuickSort(nums, privot + 1, high);
    }
}

//遍历打印数组
void Print(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        cout << nums[i] << " ";
    }
}

int main() {
    const int numsSize = 7;
    int nums[numsSize] = {64, 34, 25, 12, 22, 11, 90};
    // QuickSort(nums, 0, numsSize - 1);
    BubbleSort(nums, numsSize);
    Print(nums, numsSize);
    return 0;
}