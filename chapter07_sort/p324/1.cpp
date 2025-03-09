/*
7.【2016统考真题】已知由n(n≥2)个正整数构成的集合 A=
{ak|0≤k<n)，将其划分为两个不相交的子集A1和A2，元素个数分别是n1和n2，A1和A2中的元素之和分别为S1和S2。设计一个尽可能高效的划分算法，满足|n1一n2|最小且|S1-S2|最大。
输出：
4 8 8 12 16 20
-4
*/

#include <stdio.h>

// 分区函数
int Partition(int a[], int low, int high) {
  // begin
  int low_temp = low, high_temp = high, k = high / 2;
  int flag = 1;
  int i, s1 = 0, s2 = 0;

  while (flag) {
    int x = a[low];
    while (low < high) {
      while (low < high && x <= a[high]) high--;
      a[low] = a[high];
      while (low < high && x >= a[low]) low++;
      a[high] = a[low];
    }
    a[low] = x;
    if (low == k)
      flag = 0;
    else if (low < k) {
      low++;
      high = high_temp;
    } else {
      high--;
      low = low_temp;
    }
  }

  for (i = 0; i < k; i++) s1 += a[i];
  for (i = k; i <= high_temp; i++) s2 += a[i];

  return s2 - s1;
}

int main() {
  int a[] = {16, 20, 8, 4, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  // 返回s1-s2的值
  int x = Partition(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  printf("%d ", x);

  return 0;
}
