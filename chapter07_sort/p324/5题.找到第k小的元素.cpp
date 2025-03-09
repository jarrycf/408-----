/*
试编写一个算法，使之能够在数组L[1..n]
中找出第k小的元素（即从小到大排序后处于第k个位置的元素）。
*/

#include <stdio.h>

// 分区函数
int kth_elem(int a[], int low, int high, int k) {  // 第k小的数
  // begin
  int x = a[low];
  int low_temp = low;
  int high_temp = high;
  while (low < high) {
    while (low < high && x <= a[high]) high--;
    a[low] = a[high];
    while (low < high && x >= a[low]) low++;
    a[high] = a[low];
  }
  a[low] = x;
  if (low == k)
    return a[low];
  else if (low > k)
    return kth_elem(a, low_temp, low - 1, k);
  else
    return kth_elem(a, low + 1, high_temp, k);
}

int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);
  int k = 3;
  int z = kth_elem(a, 0, n - 1, k - 1);

  printf("%d ", z);

  printf("\n");

  return 0;
}
