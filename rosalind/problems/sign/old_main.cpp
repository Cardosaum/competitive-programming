#include <algorithm>
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
#define mt make_tuple
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
    int n;
    cin >> n;
    vi v;
    for (int i = -n; i <= n; i++) {
        if (!i) {
            continue;
        } else {
            v.pb(i);
        }
    }
    set<vi> s;
    for (ull i = 0; i < v.size(); i++) {
        vi vvi;
        for (ull j = 0; j < v.size(); j++) {
            if (v[i] == v[j] || v[i] == -v[j]) {
                continue;
            }
            vvi.pb(v[j]);
        }
        cout << "* " << v[i] << endl;
        sort(all(vvi));

        do {
            rep(g, vvi.size()) {
                if (vvi[g] == v[i] || vvi[g] == -v[i]) {
                    continue;
                }
                cout << vvi[g] << ",";
            }
            cout << endl;
            vi tmp{v[i]};
            tmp.insert(tmp.end(), all(vvi));
            s.ep(tmp);
        } while (next_permutation(all(vvi)));
        cout << endl;
    }
}
