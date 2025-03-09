#include <stdio.h>

// 分区函数
int Partition(int a[], int low, int high, int n) {
  int i = low, j = high;
  int x = a[low];
  int s1 = 0, s2 = 0;

  // 分区操作
  while (i < j) {
    while (i < j && a[j] >= x) j--;  // 从右往左找到小于 x 的元素
    if (i < j) a[i++] = a[j];
    while (i < j && a[i] <= x) i++;  // 从左往右找到大于 x 的元素
    if (i < j) a[j--] = a[i];
  }
  a[i] = x;  // 将基准元素放回到正确位置

  // 计算左右两部分的和
  for (int k = 0; k < i; k++) s1 += a[k];
  for (int k = i; k < n; k++) s2 += a[k];

  // 返回和的差的绝对值
  return (s2 > s1) ? s2 - s1 : s1 - s2;
}

int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);
  int x = Partition(a, 0, n - 1, n);

  // 输出排序后的数组
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  // 输出和的差
  printf("%d ", x);

  return 0;
}
