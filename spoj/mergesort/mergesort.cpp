// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(const vector<T> &vec) {
    for (auto i: vec)
        cout << i << " ";
    cout << endl;
}

template <typename T>
void read_vector(vector<T>&vec) {
    T i;
    while (cin>>i)
        vec.push_back(i);
}

template <typename T>
void mergesort(vector<T>& vec) {
    if (vec.size() <= 1) return;

    vector<T> left, right;
    int middle = vec.size() / 2;

    for (int i = 0; i < middle; i++) left.push_back(vec[i]);
    for (int i = middle; i < vec.size(); i++) right.push_back(vec[i]);

    mergesort(left);
    mergesort(right);

    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) vec[k++] = left[i++];
        else vec[k++] = right[j++];
    }

    while (i < left.size()) vec[k++] = left[i++];
    while (j < right.size()) vec[k++] = right[j++];
}

int main() {
    vector<int> v;
    read_vector(v);
    mergesort(v);
    print_vector(v);
    return 0;
}