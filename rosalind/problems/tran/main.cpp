#include <bits/stdc++.h>
#include <iomanip>
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

void tt(char a, char b, ull *transition, ull *transversion) {
    if (a == b) {
        return;
    } else if ((a == 'A' && b == 'G') || (b == 'A' && a == 'G') ||
               (a == 'C' && b == 'T') || (b == 'C' && a == 'T')) {
        *transition += 1;
    } else {
        *transversion += 1;
    }
    return;
}

int main() {
    SPEED;
    map<ull, string> genes;
    string s;
    ull gene = -1;
    while (cin >> s) {
        if (s.front() == '>') {
            gene++;
            genes[gene] = "";
        } else {
            genes[gene] += s;
        }
    }
    ull transition = 0;
    ull transversion = 0;
    rep(i, genes[0].size()) {
        tt(genes[0][i], genes[1][i], &transition, &transversion);
        // cout << genes[0][i] << " " << genes[1][i] << " " << transition << " "
        // << transversion << endl;
    }
    cout << fixed << setprecision(11);
    cout << (ld)transition / (ld)transversion << endl;
}
