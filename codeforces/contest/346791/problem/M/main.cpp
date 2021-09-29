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

// int main() {
//     SPEED;
//     ull N, T;
//     cin >> N >> T;
//     vector<pair<ull, ull>> v(N);
//     vector<vector<ull>> DP(N * N);
//     for (auto &i : v) {
//         ull t, d;
//         cin >> t >> d;
//         i = mp(t, d);
//     }
// }
int n;
int t;
int tab[MAX];
vector<pair<int, int>> vp;

int dp(int dias, int i) {
    if (i >= n)
        return 0;

    int pega, npega;
    vector<int> v;

    if (dias + vp[i].ff <= t) {
        pega = vp[i].ss + dp(dias + vp[i].ff, i + 1);
        v.pb(i);
        npega = dp(dias, i + 1);
    } else {

        npega = dp(dias, i + 1);
        pega = dp(dias, i + 1);
    }

    return max(pega, npega);
}

int main() {
    sws;
    memset(tab, -1, sizeof(tab));

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int ti, d;
        cin >> ti >> d;
        vp.pb({ti, d});
    }

    int ans = dp(0, 0);
    cout << ans << endl;

    return 0;
}
