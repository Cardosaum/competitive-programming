#include <bits/stdc++.h>
#include <tuple>
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

int main() {
    SPEED;
    ll n, m, k;
    cin >> n >> m >> k;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    v.push_back(0);
    vector<tuple<ll, ll, ll>> op(m);
    for (auto &i : op) {
        ll l, r, d;
        cin >> l >> r >> d;
        i = make_tuple(l, r, d);
    }
    vll op_delta(m + 1);
    while (k--) {
        ll x, y;
        cin >> x >> y;
        x--;
        op_delta[x]++;
        op_delta[y]--;
    }
    ll s = 0;
    vll op_psum(m + 1);
    rull(i, op_delta.size()) {
        s += op_delta[i];
        op_psum[i] += s;
    }

    vll v_delta(n + 1);
    rull(i, op.size()) {
        ll l, r, d;
        tie(l, r, d) = op[i];
        v_delta[l - 1] += (d * op_psum[i]);
        v_delta[r] += -(d * op_psum[i]);
    }

    s = 0;
    vll v_psum(n + 1);
    rull(i, v_delta.size()) {
        s += v_delta[i];
        v_psum[i] += s + v[i];
    }

    v_psum.pop_back();
    for (auto const &i : v_psum)
        cout << i << " ";
    cout << endl;
}
