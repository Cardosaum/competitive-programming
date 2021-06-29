#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED                                                                  \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr)
#define endl '\n'
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

pullull far(ull n, ull m, ull *i, ull *j) {
    pullull p;
    p.first = max({*i + (n - *i), max((ull)1, *i - 1)});
    p.second = max({*j + (m - *j), max((ull)1, *j - 1)});
    *i = p.first;
    *j = p.second;
    // cout << p.first << "," << p.second << endl;
    return p;
}

int main() {
    SPEED;
    ull t;
    cin >> t;
    while (t--) {
        ull n, m, i, j;
        cin >> n >> m >> i >> j;
        auto xy1 = far(n, m, &i, &j);
        auto xy2 = far(n, m, &i, &j);
        cout << xy1.first << " " << xy1.second << " " << xy2.first << " "
             << xy2.second << endl;
    }
}
