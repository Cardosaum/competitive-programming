#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED                                                                  \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr)
#define endl '\n'
#define TESTS                                                                  \
    ull T;                                                                     \
    cin >> T;                                                                  \
    while (T--)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rint(i, n) for (int i = 0; i < (int)(n); i++)
#define rull(i, n) for (ull i = 0; i < (ull)(n); i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define te try_emplace

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ull, ull> pullull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;
typedef istringstream iss;
typedef set<int> si;
typedef set<ull> sull;
typedef map<int, int> mii;
typedef map<ull, ull> mullull;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<char, int> mci;

typedef set<int>::iterator si_it;
typedef map<int, int>::iterator mii_it;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

[[maybe_unused]] const int INF = 1e9 + 7;
[[maybe_unused]] const int MOD = 1e9 + 7;
[[maybe_unused]] const int MAXN = 1e6 + 3;

ull bt(ull n, ull k) {
    ull ith = 0;
    for (ull i = 1; ith != k; i++) {
        if (i % n == 0)
            continue;
        ith++;
        if (ith == k) {
            return i;
        }
    }
    return 0;
}

ull ty(ull n, ull k) {
    auto r = ((k / (n - 1)) * n);
    auto m = k % (n - 1);
    if (m == 0)
        r--;
    else
        r += m;
    return r;
}

int main() {
    SPEED;
    // cout << 3 << ":" << 7 << "= " << bt(3, 7) << endl;
    // cout << 3 << ":" << 7 << "= " << ty(3, 7) << endl;
    // cout << 4 << ":" << 12 << "= " << bt(4, 12) << endl;
    // cout << 4 << ":" << 12 << "= " << ty(4, 12) << endl;
    // cout << 9 << ":" << 101 << "= " << bt(9, 101) << endl;
    // cout << 9 << ":" << 101 << "= " << ty(9, 101) << endl;
    TESTS {
        ull n, k;
        cin >> n >> k;
        cout << ty(n, k) << endl;
    }
}
