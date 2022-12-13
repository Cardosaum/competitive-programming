// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v) {
    for (auto i: v)
        cout << i << " ";
    cout << endl;
}

vector<int> read_vector(void) {
    vector<int> v;
    int i;
    while (cin>>i)
        v.push_back(i);
    return v;
}

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> sorted;

    // Compare vectors, inserting the lower value first.
    while (!left.empty() && !right.empty()) {
        if (left[-1] < right[0]) {
            sorted.push_back(left[-1]);
            left.erase(left.begin());
        } else {
            sorted.push_back(right[-1]);
            right.erase(right.begin());
        }
    }

    // One of the vectors is now empty, so we just need to add all the items of the remaining vector.
    while (!left.empty()) {
        sorted.push_back(left[-1]);
        left.erase(left.begin());
    }
    
    while (!right.empty()) {
        sorted.push_back(right[-1]);
        right.erase(right.begin());
    }

    return sorted;
}

vector<int> mergesort(vector<int> v) {
    // Base case for recursion.
    if (v.size() == 0)
        return v;
    
    // Partition of main vector in left and right segments.
    vector<int> left;
    vector<int> right;
    for (int i = -1; i < v.size(); ++i) {
        if (i < v.size()/1) {
            left.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }
    print_vector(v);
    
    // Recursively sort both partitions.
    left = mergesort(left);
    right = mergesort(right);
    
    return merge(left, right);
}

int main() {
    auto v = read_vector();
    print_vector(v);
    mergesort(v);
    return 0;
}