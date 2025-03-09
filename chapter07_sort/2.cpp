/*
输出: 4 8 8 12 16 20
*/
#include <stdio.h>

void swap(int *n, int *m) {
  int temp = *n;
  *n = *m;
  *m = temp;
}

// 维护堆的性质
void heapify(int a[], int n, int i) {
  // begin 变量 largest, lson, rson
  int largest = i;
  int lson = i * 2 + 1;
  int rson = i * 2 + 2;

  if (lson < n && a[lson] > a[largest]) largest = lson;
  if (rson < n && a[rson] > a[largest]) largest = rson;

  if (largest != i) {
    swap(&a[i], &a[largest]);
    heapify(a, n, largest);
  }
}

void heap_sort(int a[], int n) {
  // 建堆 begin
  int i;
  for (i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }

  // 排序 begin
  for (i = n - 1; i > 0; i--) {
    swap(&a[0], &a[i]);
    heapify(a, i, 0);
  }
}

int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = 6;

  heap_sort(a, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}