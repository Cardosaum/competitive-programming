// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>
using namespace std;

template <typename T>
int insertion_sort(vector<T>& v) {
    int swaps (0);
    for (int i = 1; i < v.size(); i++) {
        T key = v[i];
        int j = i - 1;
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