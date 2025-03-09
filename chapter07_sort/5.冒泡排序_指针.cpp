#include <stdio.h>
#include <stdlib.h>  // 需要包含 stdlib.h 以使用 atoi()
#include <string.h>

// 冒泡排序的思想：通过两两交换将最大的数移到最后
// 指针法
void bubbleSort(char **a, int n) {  // char *a[]
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (atoi(*(a + j)) > atoi(*(a + j + 1))) {
        // if (strcmp(*(a + j), *(a + j + 1)) > 0) {
        char *temp = *(a + j);
        *(a + j) = *(a + j + 1);
        *(a + j + 1) = temp;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%s ", a[i]);
    }
    printf("\n");
  }
}

// 主函数
int main() {
  // char *a[] 是字符数组，字符串char a[] = "23154";
  char *a[] = {"16", "20", "8", "4", "8", "12"};
  // char *a[] = {"B", "C", "A", "D", "C", "B"};
  int n = sizeof(a) / sizeof(a[0]);

  bubbleSort(a, n);

  for (int i = 0; i < n; i++) {
    printf("%s ", a[i]);
  }
  printf("\n");

  return 0;
}
