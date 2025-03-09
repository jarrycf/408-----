#include <stdio.h>

void swap(int &n, int &m) {
  int temp = n;
  n = m;
  m = temp;
}

void bubbleSort(int a[], int n) {
  // begin
  for (int i = 0; i < n - 1; i++) {
    bool flag = false;
    for (int j = n - 1; j > i; j--) {
      if (a[j - 1] > a[j]) {
        swap(a[j - 1], a[j]);
        flag = true;
      }
    }
    if (flag == false) break;
  }
}

// 主函数
int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  bubbleSort(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
