#include <stdio.h>

void InsertSort(int a[], int n) {
  // 遍历每个待排序元素，从第 2 个元素开始, 从小到大排为4 8 8* 12 16 20
  // begin
  int i, j, temp;
  for (i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      temp = a[i];
      for (j = i - 1; j >= 0 && temp < a[j]; j--) {
        a[j + 1] = a[j];
      }
      a[j + 1] = temp;
    }
  }
}

int main() {
  int a[6] = {16, 20, 8, 4, 8, 12};  // 原始数组
  InsertSort(a, 6);

  // 输出排序后的数组
  printf("Sorted array: ");
  for (int i = 0; i < 6; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
