/*
输出结果: 4 8 8 12 16 20
*/

#include <stdio.h>

void swap(int &n, int &m) {
  int temp = n;
  n = m;
  m = temp;
}

// 选择排序
void selectionSort(int a[], int n) {
  // begin
}

// 主函数
int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  selectionSort(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
