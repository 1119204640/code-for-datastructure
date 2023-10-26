#include <iostream>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//简单选择排序
void SimpleSelectSort(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        int min = i;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(&nums[i], &nums[min]);
        }
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

    SimpleSelectSort(nums, numsSize);
    Print(nums, numsSize);
    return 0;
}