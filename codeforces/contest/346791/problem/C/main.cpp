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

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define llu long long unsigned

int main() {
    ll i;
    cin >> i;
    map<ll, set<ll>> infra;
    map<pair<ll, ll>, ll> cont;
    ll a, b;
    while (i--) {
        cin >> a >> b;
        infra[a].insert(-b);
        cont[{a, b}] += 1;
    }

    string stmp;
    getline(cin, stmp);
    getline(cin, stmp);

    ull m = 0;
    stringstream s(stmp);
    while (m == 0) {
        string y;
        s >> y;
        try {
            m = std::stoull(y);
            break;
        } catch (...) {
            ;
        }
    }

    getline(cin, stmp);

    while (m--) {
        cin >> a;
        if (infra.find(a) != infra.end()) {
            cout << "Teje preso, " << a << "!\n";
            for (auto k : infra[a]) {
                cout << "- Art. " << -k << ": " << cont[{a, -k}]
                     << " ocorrencia(s).\n";
            }
        } else {
            cout << "Grato, cidadao " << a << ".\n";
        }
    }
}
