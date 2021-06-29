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

int main() {
    SPEED;
    TESTS {
        ull n;
        cin >> n;
        map<ull, set<ull>> m;
        for (ull i = 1; i <= n; i++) {
            ull x;
            cin >> x;
            if (x > n * 2 + 1)
                continue;
            m[x].insert(i);
        }
        // for (auto [k, v] : m) {
        //     cout << "* " << k << ": ";
        //     for (auto i : v) {
        //         cout << i << ",";
        //     }
        //     cout << endl;
        // }
        ull c = 0;
        for (auto [k1, v1] : m) {
            for (auto [k2, v2] : m) {
                auto p = k1 * k2;
                if (k1 == k2 || p > n * 2 + 1)
                    continue;
                for (auto i : v1) {
                    for (auto j : v2) {
                        if (p == i + j)
                            c++;
                        else if (p > i + j)
                            break;
                    }
                }
            }
        }
        cout << c / 2 << endl;
    }
}
