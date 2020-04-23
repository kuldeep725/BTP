#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VAL 100000

int main (int argc, char *argv[]) {

  srand(time(NULL));

  if (argc < 2) {
    printf("One argument missing.\n");
    return -1;
  }  
  int n = atol(argv[1]);

  for (int i = 0; i < n; i++) {
    // for first half - with 0.6 probability, we insert and
    // with 0.2 probability, we delete and
    // with 0.2 probability, we search
    if (i < n/2) {
      if (rand()/(double)RAND_MAX < 0.6) {
        printf("0 %d\n", rand() % MAX_VAL);
      } else if (rand()/(double)RAND_MAX < 0.8) {
        printf("1 %d\n", rand() % MAX_VAL);
      } else {
        printf("2 %d\n", rand() % MAX_VAL);
      }
    }
    // for the second half - // with 0.2 probability, we insert and 
    // with 0.3 probability, we delete and 
    // with 0.5 probability, we search 
     
    else {
      if (rand()/(double)RAND_MAX < 0.2) {
        printf("0 %d\n", rand() % MAX_VAL);
      } else if (rand()/(double) RAND_MAX < 0.5) {
        printf("1 %d\n", rand() % MAX_VAL);
      } else {
        printf("2 %d\n", rand() % MAX_VAL);
      }
    }
  }
  return 0;
}