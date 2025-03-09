#include <stdio.h>

void ShellSort(int a[], int n) {
  // 第一次遍历4, 16
  int i, j, temp;
  int d;  // 步长变化
  // begin
  for (d = n / 2; d >= 1; d = d / 2) {
    for (i = d; i < n; i++) {
      if (a[i] < a[i - d]) {
        temp = a[i];
        for (j = i - d; j >= 0 && temp < a[j]; j = j - d) {
          a[j + d] = a[j];
        }
        a[j + d] = temp;
      }
    }
  }
}

int main() {
  int a[6] = {16, 20, 8, 4, 8, 12};  // 原始数组
  ShellSort(a, 6);

  // 输出排序后的数组
  printf("Sorted array: ");
  for (int i = 0; i < 6; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
