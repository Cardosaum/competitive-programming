#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n, m, s, tmp1, tmp2;
    cin >> n >> m;
    // cout << "N: " << n << "\tM: " << m << "\n";
    for (a = b = s = 0; ; ++a) {
        // cout << "A: " << a << "\tB: " << b << "\tS: " << s << "\n";
        if ((a*a > n || b > n) && (a > m || b*b > m)) {
            break;
        }
        if (a*a > n || a > m) {
            a = -1;
            ++b;
            continue;
        }

        tmp1 = a*a + b;
        tmp2 = a + b*b;
        if (tmp1 == n && tmp2 == m) {
            ++s;
            ++b;
            a = -1;
            continue;
        }
    }
    // cout << "\n\n";
    // cout << s << "\n";
    cout << s;
}
