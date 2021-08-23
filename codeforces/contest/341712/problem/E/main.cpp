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
    TESTS {
        ull n;
        cin >> n;
        vull v(n);
        for (auto &i : v)
            cin >> i;
        sort(all(v));
        sull s(all(v));

        ull candidate = 0;
        if (n % 2) {
            candidate = v[n / 2] * v[n / 2];
        } else {
            candidate = v.front() * v.back();
        }
        s.insert(1);
        s.insert(candidate);

        auto f = factorize(candidate);
        auto d = all_divisors(f);
        if (s == d) {
            cout << candidate << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
