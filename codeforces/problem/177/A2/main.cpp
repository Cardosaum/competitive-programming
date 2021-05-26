#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int x;
    int i {0};
    int j {-1};
    cin >> n;
    vector<int> v;
    string s;

    while (getline(cin, s)) {
        istringstream ss(s);
        while (ss >> x) {
            // printf("x: %i\n", x);
            if (j == (n-1)/2) { // "middle" row
                // printf("\t(1) x: %i; j: %i\n", x, j);
                v.push_back(x);
                ++i;
                continue;
            }
            if (i%n == (n-1)/2 ) { // "middle" column
                // printf("\t(2) x: %i; i%%n: %i\n", x, i%n);
                v.push_back(x);
                ++i;
                continue;
            }
            if ( i%n == j ) { // main diagonal
                // printf("\t(3) x: %i; i%%n: %i; j: %i\n", x, i%n, j);
                v.push_back(x);
                ++i;
                continue;
            }
            if ( i%n == n-j-1 ) {
                // printf("\t(4) x: %i\n", x);
                v.push_back(x);
                ++i;
                continue;
            }
            // if (j == (n-1)/2 || i%n == (n-1)/2 || i%n == j || i%n == n-j) {
            //     printf("\tx: %i\n", x);
            //     v.push_back(x);
            // }
            ++i;
        }
        ++j;
    }
    cout << accumulate(v.begin(), v.end(), 0);
}
