#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

int n, m;
std::set<std::pair<int,int>> mset;

int getValue() {
  return (rand()%n);
}

int main (int argc, char *argv[]) {
  
  srand(time(NULL));

  if (argc < 3) {
    printf("Argument missing.\n");
    return -1;
  }

  n = atol(argv[1]);
  m = atol(argv[2]);
  printf("%d\n%d\n", n, m);

  for (int i = 0; i < m; i++) {
    int u = getValue();
    int v;
    int w = getValue();
    while((v = getValue()) == u);
    if(mset.find({u, v}) != mset.end() 
      || mset.find({v, u}) != mset.end()) {
        i--;
        continue;
    }
    printf("%d %d %d\n", u, v, w);
    mset.insert({u, v});
  }

  return 0;
} 