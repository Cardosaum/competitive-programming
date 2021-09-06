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

ull least_factor(ull n) {
    ull x = 2;
    ull limit = (ull)sqrt(n);
    while (x <= limit) {
        if (n % x == 0)
            return x;
        else
            x++;
    }
    return n;
}

mullull factorize(ull n) {
    mullull factors;
    while (n != 1) {
        ull factor = least_factor(n);
        n /= factor;
        factors[factor]++;
    }
    return factors;
}

sull all_divisors(mullull &factorized) {
    sull d;
    d.insert(1);
    if (factorized.empty())
        return d;
    vector<pair<ull, ull>> factors;
    for (auto const &[k, v] : factorized)
        factors.emplace_back(mp(k, v));
    ull nfactors = factors.size();
    vull f(nfactors);
    while (1) {
        ull s = 1;
        vull tmp;
        rull(i, nfactors) { tmp.emplace_back(pow(factors[i].first, f[i])); }
        for (auto const &i : tmp)
            s *= i;
        d.insert(s);
        ull I = 0;
        while (1) {
            f[I]++;
            if (f[I] <= factors[I].second) {
                break;
            }
            f[I] = 0;
            I++;
            if (I >= nfactors) {
                goto all_divisors_end;
            }
        }
    }
all_divisors_end:
    return d;
}

int main() {
    SPEED;
    ull n;
    cin >> n;
    vector<pullull> v(n);
    map<ull, mullull> factors;
    map<ull, sull> divisors;
    for (auto &i : v) {
        ull x, y;
        cin >> x >> y;
        i.first = x;
        i.second = y;
        if (factors[x].empty()) {
            auto f = factorize(x);
            auto d = all_divisors(f);
            factors[x] = f;
            divisors[x] = d;
        }
    }
    for (ull i = 0; i < v.size(); i++) {
        auto const &[x, y] = v[i];
        if (!y) {
            cout << divisors[x].size() << endl;
        } else {
            sull k;
            for (auto const &j : divisors[x]) {
                bool add = true;
                for (ull g = y - 1; g < i; g++) {
                    if (v[g].first % j == 0) {
                        add = false;
                        break;
                    }
                }
                if (add)
                    k.insert(j);
            }
            cout << k.size() << endl;
        }
    }
    auto f = factorize(1);
    auto d = all_divisors(f);
    cout << endl;
    cout << endl;
    cout << endl;
    for (auto const &[k, vv] : f) {
        cout << k << ":" << vv;
    }
    cout << endl;
    for (auto const &i : d) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    cout << f.size() << endl;
    cout << d.size() << endl;
}