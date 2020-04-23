/* ============ LATEST ===============
// number_6e7.txt       :   16.847s 
*/

/* ============ OLD ===============
// number_1e7.txt       :   3.324s
// number_6e7.txt       :   31.219s
// number_7e7.txt       :   3m27.213s  == 207s
// number_8e7.txt       :   5m10.414s  == 310s
// number_1e8.txt       :   10m38.628s == 638s
*/

// Command : sudo perf stat -I100 -M Summary,Frontend,Frontend_Bandwidth,Memory_BW,Memory_Bound,Memory_Lat,Pipeline -x, -o mergesort_xinput.csv ./mergesort.out 700000000 < ../numbers_7e7.txt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *a, int lo, int mid, int hi) {
  int *aux = (int *) malloc((hi-lo+1) * sizeof(int));

  int i = lo, j = mid+1, k = 0;
  while(k < hi-lo+1) {
    if (i > mid)          aux[k++] = a[j++];
    else if (j > hi)      aux[k++] = a[i++];
    else if (a[i] < a[j]) aux[k++] = a[i++];
    else                  aux[k++] = a[j++];
  }
  for(int i = lo; i < hi-lo+1; i++) {
    a[i] = aux[i];
  }
  free(aux);
}

void mergesort(int *a, int lo, int hi) {
  if (lo < hi) {
    // find the middle value  
    int mid = lo + (hi-lo)/2;

    // Sort first and second halves
    mergesort(a, lo, mid);
    mergesort(a, mid+1, hi);

    // Merge the two halves
    merge(a, lo, mid, hi);
  }
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

  mergesort(a, 0, n-1);

  // for (int i = 0; i < n; i++) {
  //   printf("%d ", a[i]);
  // }
  // printf("\n");

  free(a);
  
  return 0;
}