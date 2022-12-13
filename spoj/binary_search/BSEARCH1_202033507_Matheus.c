// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <stdio.h>

// binary search function
int binary_search(int* a, int n, int x) {
  // initialize the search range as the whole array
  int left = 0;
  int right = n - 1;

  // loop until the search range is not empty
  while (left <= right) {
    // find the middle element of the search range
    int mid = left + (right - left) / 2;

    // check if the middle element is the element we are looking for
    if (a[mid] == x) {
      // if the middle element is the element we are looking for,
      // we return the 0-based index of the first occurence of the element
      // by searching for the first element that is not equal to x in the left side
      // of the search range and returning the next index
      while (mid > 0 && a[mid - 1] == x) {
        mid--;
      }
      return mid;
    }
    // if the middle element is greater than the element we are looking for,
    // we search in the left half of the search range
    else if (a[mid] > x) {
      right = mid - 1;
    }
    // otherwise, we search in the right half of the search range
    else {
      left = mid + 1;
    }
  }

  // if the element is not present in the array, return -1
  return -1;
}

int main() {
  // read the number of elements in the array and the number of queries
  int n, q;
  scanf("%d %d", &n, &q);

  // read the array
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // for each query
  for (int i = 0; i < q; i++) {
    // read the element to search for
    int x;
    scanf("%d", &x);

    // search for the element in the array and print the result
    printf("%d\n", binary_search(a, n, x));
  }

  return 0;
}
