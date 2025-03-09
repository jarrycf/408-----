#include <stdio.h>

void swap(int &n, int &m) {
  int temp = n;
  n = m;
  m = temp;
}

// 分区函数
int Partition(int a[], int low, int high) {
  // begin
  while (low < high) {
    while (low < high && a[low] % 2 == 1) low++;
    while (low < high && a[high] % 2 == 0) high--;
    if (low < high) {
      swap(a[low], a[high]);
      low++;
      high--;
    }
  }
}

int main() {
  int a[] = {16, 20, 8, 4, 8, 13};
  int n = sizeof(a) / sizeof(a[0]);
  Partition(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
