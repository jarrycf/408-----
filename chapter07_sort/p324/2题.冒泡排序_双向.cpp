#include <stdio.h>

void swap(int &n, int &m) {
  int temp = n;
  n = m;
  m = temp;
}

void bubbleSort_double(int a[], int n) {
  // begin
  int left = 0, right = n - 1;
  int flag = 1;
  while (left < right && flag) {
    flag = 0;
    for (int j = left; j < right; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        flag = 1;
      }
    }
    right--;

    for (int j = right; j > left; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        flag = 1;
      }
    }
    left++;
  }
}

// 主函数
int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  bubbleSort_double(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
