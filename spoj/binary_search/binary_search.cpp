// Assignment for PAA discipline, Universidade de Brasilia
// Student: Matheus Cardoso
// Code: 202033506

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end() || *it != x) {
            cout << "-1\n";
        } else {
            cout << it - arr.begin() << "\n";
        }
    }
    cout.flush();

    return 0;
}