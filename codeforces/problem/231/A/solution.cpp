#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int problems {0};
    int n;
    while (getline(cin, s)) {
        int a {0};
        istringstream iss(s);
        // cout << "Line: " << s << "\n";
        while (iss >> n) {
            // cout << "N: " << n << "\n";
            if (n == 1) {
                ++a;
            }
        }
        if (a > 1) {
            ++problems;
        }
    }
    // cout << "Total solved problems: " << problems << "\n";
    cout << problems;
}
