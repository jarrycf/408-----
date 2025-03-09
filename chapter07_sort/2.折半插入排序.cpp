#include <stdio.h>

// 折半插入排序
void BinaryInsertSort(int a[], int n) {
  // begin
  int i, j, temp, left, right, mid;

  for (i = 0; i < n; i++) {
    temp = a[i];
    left = 0;
    right = i - 1;

    while (left <= right) {
      mid = (left + right) / 2;
      if (a[mid] < temp)
        left = mid + 1;
      else
        right = mid - 1;
    }

    for (j = i - 1; j >= left; j--) {
      a[j + 1] = a[j];
    }

    a[left] = temp;
  }
}

int main() {
  int a[6] = {16, 20, 8, 4, 8, 12};  // 原始数组
  BinaryInsertSort(a, 6);

  // 输出排序后的数组
  printf("Sorted array: ");
  for (int i = 0; i < 6; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
