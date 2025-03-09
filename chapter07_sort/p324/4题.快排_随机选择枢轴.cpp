#include <stdio.h>
#include <stdlib.h>

void swap(int &n, int &m) {
  int temp = n;
  n = m;
  m = temp;
}

// 分区函数
int Partition(int a[], int low, int high) {
  // begin
  int rand_index = low + rand() % (high - low + 1);
  swap(a[rand_index], a[low]);
  int x = a[low];
  while (low < high) {
    while (low < high && x <= a[high]) high--;
    a[low] = a[high];
    while (low < high && x >= a[low]) low++;
    a[high] = a[low];
  }
  a[low] = x;
  return low;
}

// 快速排序函数
void QSort(int a[], int low, int high) {
  // begin
  int piv;
  if (low < high) {
    piv = Partition(a, low, high);
    QSort(a, low, piv - 1);
    QSort(a, piv + 1, high);
  }
}

int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);
  QSort(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
