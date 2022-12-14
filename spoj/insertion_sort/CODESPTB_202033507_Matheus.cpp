// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>
using namespace std;

template <typename T>
// this function sorts a vector of type T using insertion sort
// and returns the number of swaps performed during the sort
int insertion_sort(vector<T>& v) {
    int swaps (0);
    for (int i = 1; i < v.size(); i++) {
        // insert v[i] into the sorted sublist v[0...i-1]
        T key = v[i];
        int j = i - 1;
        // move all elements greater than key to the right
        // by one position
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
            swaps++;
        }
        v[j + 1] = key;
    }
    return swaps;
}

int main() {
    int tests;
    cin >> tests;
    // perform the insertion sort and output the number of swaps
    // for each test case
    while (tests--) {
        int vec_size;
        cin >> vec_size;
        vector<int> vec(vec_size);
        for (int i = 0; i < vec_size; i++)
            cin >> vec[i];
        auto swaps = insertion_sort(vec);
        cout << swaps << endl;
    }
}

// This is a C++ implementation of the insertion sort algorithm. The
// insertion_sort() function takes in a vector of elements of any type T and
// sorts them in ascending order. It returns the number of swaps performed in
// the process. The main() function reads in the number of test cases and then,
// for each test case, reads in a vector of integers and sorts them using the
// insertion_sort() function. It then outputs the number of swaps performed for
// each test case.
// The insertion_sort() function works by iterating through the input vector and
// taking each element in turn. For each element, it inserts it into its correct
// position in the subvector to its left by shifting the elements in the
// subvector to the right as needed, and keeping track of the number of swaps
// performed. When the entire vector has been processed, the function returns
// the total number of swaps performed.