/*
6.荷兰国族问题：设有一个仅由红，白、蓝三种颜色的条块组成的条决序列，请编写一个时间复杂度为
O(n)的算法，使得这些条块按红、白、蓝的顺序排好，即排成荷兰国旗图亲。
输出:
排序后的数组：
0 0 1 1 2 2
*/

#include <stdio.h>

void swap(int &n, int &m) {
  int temp = n;
  n = m;
  m = temp;
}

void dutch_flag_sort(int a[], int n) {
  int low = 0, mid = 0, high = n - 1;
  while (mid <= high) {
    switch (a[mid]) {
      case 0:
        swap(a[low], a[mid]);
        low++;
        mid++;
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(a[mid], a[high]);
        high--;
    }
  }
}

int main() {
  int a[] = {2, 0, 2, 1, 1, 0};
  int n = sizeof(a) / sizeof(a[0]);

  dutch_flag_sort(a, n);

  printf("排序后的数组：\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
