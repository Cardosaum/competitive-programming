// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>
using namespace std;

// template <typename T>
// void print_vector(const vector<T> &vec) {
//     for (auto i: vec)
//         cout << i << " ";
//     cout << endl;
// }

// First try
// template <typename T>
// int binary_search(const vector<T>& v, const T& target) {
//     int left = 0;
//     int right = v.size() - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (target == v[mid]) {
//             return mid;
//         } else if (target < v[mid]) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

// Second try
// template <typename T>
// int binary_search(const vector<T>& v, const T& target) {
//     int left = 0;
//     int right = v.size() - 1;
//     if (left > right) {
//         return -1;
//     }
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (target == v[mid]) {
//             return mid;
//         } else if (target < v[mid]) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

// // Third try
// template <typename T>
// int binary_search(const vector<T>& v, const T& target) {
//     int left = 0;
//     int right = v.size() - 1;
//     if (left > right) {
//         return -1;
//     }
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (target == v[mid]) {
//             return mid;
//         } else if ((target & v[mid]) == target) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

// // 4 try
// template <typename T>
// int binary_search(const vector<T>& v, const T& target) {
//     int left = 0;
//     int right = v.size() - 1;
//     if (left > right) {
//         return -1;
//     }
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (target == v[mid]) {
//             return mid;
//         } else if ((target & v[mid]) == target) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     // Check if the target is at the beginning of the input vector
//     if (target == v[0]) {
//         return 0;
//     }
//     return -1;
// }

// // 5 try
// template <typename T>
// int binary_search(const vector<T>& v, const T& target) {
//     int left = 0;
//     int right = v.size() - 1;
//     if (left > right) {
//         return -1;
//     }
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (target == v[mid]) {
//             // If the target is a duplicate element, search for the first instance
//             while (mid > 0 && v[mid - 1] == target) {
//                 mid--;
//             }
//             return mid;
//         } else if ((target & v[mid]) == target) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     // Check if the target is at the beginning of the input vector
//     if (target == v[0]) {
//         return 0;
//     }
//     return -1;
// }

// // 6 try
// template <typename T>
// int binary_search(const vector<T>& v, const T& target) {
//     int left = 0;
//     int right = v.size() - 1;
//     if (left > right) {
//         return -1;
//     }
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (target == v[mid]) {
//             // If the target is a duplicate element, search for the first instance
//             while (mid > 0 && v[mid - 1] == target) {
//                 mid--;
//             }
//             return mid;
//         } else if (target < v[mid]) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     // Check if the target is at the beginning of the input vector
//     if (target == v[0]) {
//         return 0;
//     }
//     return -1;
// }

// // 7 try, array
// int binary_search(int* arr, int n, int target) {
//     int left = 0;
//     int right = n - 1;
//     if (left > right) {
//         return -1;
//     }
//     while (left <= right) {
//         // Use a bitwise operation to calculate the midpoint value
//         int mid = left + ((right - left) >> 1);
//         if (target == arr[mid]) {
//             // If the target is a duplicate element, search for the first instance
//             while (mid > 0 && arr[mid - 1] == target) {
//                 mid--;
//             }
//             return mid;
//         } else if (target < arr[mid]) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }
//     // Check if the target is at the beginning of the array
//     if (target == arr[0]) {
//         return 0;
//     }
//     return -1;
// }

// 8 try
// Binary search function
int binary_search(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    if (left > right) {
        return -1;
    }
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == arr[mid]) {
            // If the target is a duplicate element, search for the first instance
            while (mid > 0 && arr[mid - 1] == target) {
                mid--;
            }
            return mid;
        } else if (target < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // Check if the target is at the beginning of the array
    if (target == arr[0]) {
        return 0;
    }
    return -1;
}

int main() {
    long long int N, Q;
    cin >> N >> Q;
    vector<int> vec(N);
    for (long long int i = 0; i < N; i++)
        cin >> vec[i];
    while (Q--) {
        long long int i;
        cin >> i;
        cout << binary_search(vec, i) << endl;
    }

    cout << endl;

    // // Test case: the input vector is empty
    // vector<int> v1;
    // int target1 = 5;
    // int expected_output1 = -1;
    // int output1 = binary_search(v1, target1);
    // assert(output1 == expected_output1);

    // // Test case: the target is not in the input vector
    // vector<int> v2 = {1, 2, 3, 4, 6, 7, 8, 9};
    // int target2 = 5;
    // int expected_output2 = -1;
    // int output2 = binary_search(v2, target2);
    // assert(output2 == expected_output2);

    // // Test case: the target is at the beginning of the input vector
    // vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int target3 = 1;
    // int expected_output3 = 0;
    // int output3 = binary_search(v3, target3);
    // assert(output3 == expected_output3);

    // // Test case: the target is at the end of the input vector
    // vector<int> v4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int target4 = 9;
    // int expected_output4 = 8;
    // int output4 = binary_search(v4, target4);
    // assert(output4 == expected_output4);

    // // Test case: the target is in the middle of the input vector
    // vector<int> v5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int target5 = 5;
    // int expected_output5 = 4;
    // int output5 = binary_search(v5, target5);
    // assert(output5 == expected_output5);

    // // Test case: the target is a duplicate element in the input vector
    // vector<int> v6 = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9};
    // int target6 = 3;
    // int expected_output6 = 2;
    // int output6 = binary_search(v6, target6);
    // assert(output6 == expected_output6);

    // // Test case: the input vector is sorted in descending order
    // vector<int> v7 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int target7 = 5;
    // int expected_output7 = 4;
    // int output7 = binary_search(v7, target7);
    // assert(output7 == expected_output7);

    // // Test case: the input vector contains negative numbers
    // vector<int> v8 = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0};
    // int target8 = -5;
    // int expected_output8 = 4;
    // int output8 = binary_search(v8, target8);
    // assert(output8 == expected_output8);

    // // Test case: the input vector is very large
    // const int M = 1e6;
    // vector<int> v9(M);
    // for (int i = 0; i < M; i++) {
    //     v9[i] = i;
    // }
    // int target9 = 50000;
    // int expected_output9 = 50000;
    // int output9 = binary_search(v9, target9);
    // assert(output9 == expected_output9);
}