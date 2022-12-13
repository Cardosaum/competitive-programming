// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>

using namespace std;

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
  // use faster I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // read the number of elements in the array and the number of queries
  int n, q;
  cin >> n >> q;

  // read the array
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // for each query
  for (int i = 0; i < q; i++) {
    // read the element to search for
    int x;
    cin >> x;

    // search for the element in the array and print the result
    cout << binary_search(a, n, x) << "\n";
  }

  // flush the output
  cout.flush();

  return 0;
}

// Comments: 
// 
// The binary_search() function takes in an array a of integers, the number of
// elements in the array n, and the element x to search for. It returns the
// 0-based index of the first occurence of x in the array, or -1 if x is not
// present in the array. The function first initializes the search range to be
// the whole array. It then enters a loop where it finds the middle element of
// the search range, checks if it is the element we are looking for, and updates
// the search range accordingly until the search range becomes empty or the
// element is found. In the main() function, we read the input, call the
// binary_search() function for each query, and print the result. This
// implementation is fast because it uses the binary search algorithm, which has
// a time complexity of O(log n) for searching for an element in a sorted array
// of size n. This is faster than the linear search algorithm, which has a time
// complexity of O(n).
// We've used ios_base::sync_with_stdio(false); and cin.tie(NULL); to improve
// the I/O performance of the program by disabling synchronization with the
// standard I/O streams and the flushing of the cin stream after each operation.
// We've also replaced all occurrences of endl with \n and used cout.flush()
// right before returning from main() to improve the output performance. Using
// endl causes the output stream to be flushed after each output, which can slow
// down the program. Using \n instead and manually flushing the output stream at
// the end can improve the performance. 