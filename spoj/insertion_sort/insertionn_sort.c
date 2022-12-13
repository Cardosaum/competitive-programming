#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100001

int a[MAXN];
int counts[MAXN];

int main(void) {
  int T;
  if (scanf("%d", &T) != 1) {
    fprintf(stderr, "Error: invalid input\n");
    exit(EXIT_FAILURE);
  }

  for (int t = 0; t < T; ++t) {
    int N;
    if (scanf("%d", &N) != 1) {
      fprintf(stderr, "Error: invalid input\n");
      exit(EXIT_FAILURE);
    }

    memset(counts, 0, sizeof(counts));

    int swaps = 0;
    for (int i = 1; i <= N; ++i) {
      if (scanf("%d", &a[i]) != 1) {
        fprintf(stderr, "Error: invalid input\n");
        exit(EXIT_FAILURE);
      }
      swaps += counts[a[i]];
      counts[a[i]]++;
    }

    printf("%d\n", swaps);
  }

  return 0;
}
