// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

// This line includes a standard header file that defines various functions
// and macros that are commonly used in C++ programs. This header file
// provides some useful functions, such as input/output operations and
// mathematical functions, that are not part of the core C++ language.
#include <bits/stdc++.h>

// This line tells the compiler that we are using the standard namespace
// in our program. This allows us to use functions and variables from
// the standard library without having to qualify their names with the
// std:: prefix.
using namespace std;

// This line defines a function named "print_vector" that takes a
// reference to a vector of elements of some type T as an argument.
// This function doesn't return a value, so it is declared as "void".
template <typename T>
void print_vector(const vector<T> &vec) {
    // This line defines a loop that iterates over the elements in the
    // vector. For each element in the vector, the loop prints the
    // element to the standard output stream (cout) and a space character
    // after it.
    for (auto i: vec)
        cout << i << " ";

    // This line prints a newline character (endl) to the standard output
    // stream, which causes the output to be printed on a new line.
    cout << endl;
}

// This function is similar to the "print_vector" function defined above,
// but it takes a reference to a vector of elements of some type T as an
// argument and reads values from the standard input stream (cin) into
// the vector.
template <typename T>
void read_vector(vector<T>&vec) {
    // This line declares a variable of some type T named "i".
    T i;

    // This line defines a loop that reads values from the standard input
    // stream (cin) into the variable "i" until there are no more values
    // to read. For each value that is read, the loop adds it to the end
    // of the vector.
    while (cin>>i)
        vec.push_back(i);
}

// This function is a recursive implementation of the merge sort
// algorithm, which is a comparison-based sorting algorithm with a
// time complexity of O(n log n) in the average and worst cases.
template <typename T>
void mergesort(vector<T>& vec) {
    // This line checks if the size of the vector is less than or equal
    // to 1. If this is the case, then the vector is already sorted, so
    // we simply return from the function without doing anything.
    if (vec.size() <= 1) return;

    // These lines declare two vectors named "left" and "right". These
    // vectors will be used to store the left and right halves of the
    // input vector, respectively.
    vector<T> left, right;

    // This line calculates the middle index of the input vector by
    // dividing its size by 2.
    int middle = vec.size() / 2;

    // These lines define two loops that iterate over the elements in
    // the input vector. The first loop adds the elements from the
    // beginning of the vector up to the middle index to the "left"
    // vector. The second loop adds the remaining elements from the
    // middle index to the end of the vector to the "right" vector.
    for (int i = 0; i < middle; i++) left.push_back(vec[i]);
    for (int i = middle; i < vec.size(); i++) right.push_back(vec[i]);

    // These lines recursively sort the left and right halves of the
    // input vector using the same merge sort algorithm.
    mergesort(left);
    mergesort(right);

    // These lines declare three variables: "i", "j", and "k". These
    // variables will be used to keep track of the current index in the
    // left, right, and input vectors, respectively.
    int i = 0, j = 0, k = 0;

    // This line defines a loop that continues until the "i" variable is
    // greater than or equal to the size of the "left" vector or the "j"
    // variable is greater than or equal to the size of the "right" vector.
    // This means that the loop will continue until one of the two vectors
    // has been completely processed.
    while (i < left.size() && j < right.size()) {
        // This line checks if the element at the current index of the
        // "left" vector is less than the element at the current index of
        // the "right" vector. If it is, then the element from the "left"
        // vector is added to the "k" index of the original vector and the
        // "i" variable is incremented by 1. Otherwise, the element from
        // the "right" vector is added to the "k" index of the original
        // vector and the "j" variable is incremented by 1.
        if (left[i] < right[j]) vec[k++] = left[i++];
        else vec[k++] = right[j++];
    }

    // These lines define two loops that are executed if the "left" or
    // "right" vector still has remaining elements after the main loop
    // has finished. These loops simply add the remaining elements from
    // the "left" or "right" vector to the original vector.
    while (i < left.size()) vec[k++] = left[i++];
    while (j < right.size()) vec[k++] = right[j++];
}

int main() {
    // This line declares a vector of integers named "v". This vector
    // will be used to store the values that are read from the standard
    // input stream.
    vector<int> v;

    // This line calls the "read_vector" function defined earlier and
    // passes the "v" vector as an argument. This causes the function
    // to read values from the standard input stream and store them
    // in the vector.
    read_vector(v);

    // This line calls the "mergesort" function defined earlier and
    // passes the "v" vector as an argument. This causes the function
    // to sort the elements of the vector in ascending order using the
    // merge sort algorithm.
    mergesort(v);

    // This line calls the "print_vector" function defined earlier and
    // passes the "v" vector as an argument. This causes the function
    // to print the elements of the vector to the standard output stream.
    print_vector(v);

    // This line returns 0 to indicate that the program executed successfully.
    return 0;
}

// This program reads a sequence of integer values from the standard input
// stream, sorts the values in ascending order using the merge sort algorithm,
// and then prints the sorted sequence of values to the standard output stream.
// The program uses template functions to allow the sorting and printing of
// vectors containing elements of any type that supports the less-than operator.