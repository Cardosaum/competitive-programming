#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <valarray>
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
    ull I;
    cin >> I;
    map<ull, map<ull, ull>> infractions;
    rull(i, I) {
        ull p, a;
        cin >> p >> a;
        infractions[p][a]++;
    }
    // for (auto const &[k, v] : infractions) {
    //     cout << k << endl;
    //     for (auto const &[kk, vv] : v) {
    //         cout << kk << ": " << vv << ", " << endl;
    //     }
    //     cout << endl;
    // }

    ull M = 0;
    string a;
    getline(cin, a);
    getline(cin, a);
    stringstream s(a);
    while (M == 0) {
        // cout << a << endl;
        string b;
        s >> b;
        // cout << b << endl;
        try {
            M = std::stoull(b);
            // cout << "ACHEI " << b << endl;
            break;
        } catch (...) {
            ;
        }
    }
    getline(cin, a);
    rull(j, M) {
        ull n;
        cin >> n;
        if (infractions[n].empty()) {
            cout << "Grato, cidadao " << n << "." << endl;
        } else {
            cout << "Teje preso, " << n << "!" << endl;
            vector<pair<ull, ull>> tmp;
            for (auto const &[k, v] : infractions[n]) {
                tmp.emplace_back(mp(v, k));
            }
            sort(all(tmp), [](const pullull &p1, const pullull &p2) {
                if (p1.se != p2.se)
                    return p1.fi > p2.fi;
                return p1.se < p2.se;
            });
            for (auto const &i : tmp) {
                cout << "- Art. " << i.second << ": " << i.first
                     << " ocorrencia(s)." << endl;
            }
        }
    }
}
