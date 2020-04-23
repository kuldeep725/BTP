// number_1e7.txt     :   3.206s
// number_1e8.txt     :   38.042s
// number_2e8.txt     :   71s

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
  
  if (argc < 2) {
    printf("One argument missing.\n");
    return -1;
  }  
  int n = atol(argv[1]);
  int *a = (int *) malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  qsort(a, n, sizeof(int), compare);

  // for (int i = 0; i < n; i++) {
  //   printf("%d ", a[i]);
  // }
  // printf("\n");

  free(a);

  return 0;
}