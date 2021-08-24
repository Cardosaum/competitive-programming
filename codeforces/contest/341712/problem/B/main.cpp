#include <bits/stdc++.h>
#include <cmath>
#include <random>
#include <stdexcept>
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

ull len_n(ull const &x) { return (ull)(trunc(log10(x)) + 1); }

sull primes(ull n) {
    // return all prime number in range [2, n]
    sull prime;
    sull composite;
    for (ull i = 2; i <= n; i++) {
        if (composite.find(i) != composite.end())
            continue;
        for (ull j = i * i; j <= n; j += i)
            composite.insert(j);
        prime.insert(i);
    }
    return prime;
}

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
    random_device rd;
    mt19937 gen(rd());
    // auto p = primes(5000);
    // map<ull, sull> m;
    // for (auto const &i : p)
    //     m[len_n(i)].insert(i);
    // for (auto const &[k, v] : m) {
    //     cout << k << ": ";
    //     for (auto const &j : v) {
    //         cout << j << ", ";
    //     }
    //     cout << endl;
    // }
    // return 0;

    TESTS {
        ull NCS = 0;
        ull x, y, g;
        cin >> x >> y >> g;
        // int tmp_a_u = (int)pow(10, x) - 1;
        // int tmp_a_l = (int)pow(10, x - 1);
        // int tmp_b_u = (int)pow(10, y) - 1;
        // int tmp_b_l = (int)pow(10, y - 1);
        //
        int tmp_g_u = (int)pow(10, g) - 1;
        int tmp_g_l = (int)pow(10, g - 1);
        if (tmp_g_l == 1)
            tmp_g_l++;
        //
        // cout << tmp_a_l << ":" << tmp_a_u << " ; " << tmp_b_l << ":" <<
        // tmp_b_u
        //      << endl;
        ull xa = INF;
        ull xb = INF;
        ull xg = INF;
        do {
            NCS++;
            // uniform_int_distribution<> a(tmp_a_l, tmp_a_u);
            // uniform_int_distribution<> b(tmp_b_l, tmp_b_u);
            uniform_int_distribution<> gd(tmp_g_l, tmp_g_u);
            // xa = a(gen);
            // xb = b(gen);
            xg = gd(gen);
            auto f = factorize(xg);
            auto d = all_divisors(f);
            cout << xg << ") ";
            for (auto const &[k, v] : f)
                cout << k << ":" << v << " ";
            cout << endl;
            // xa = *d.;
            // xb = *d.rbegin();
            // while (len(xa)) {
            // }
        } while (0);
        //
        // cout << x << " " << y << " : " << g << endl;
        // cout << xa << ": " << xb << " , " << gcd(xa, xb) << " = " << NCS
        //      << endl;
        // break;
        //
        // cout << xa << " " << xb << " (" << g << ") " << NCS << endl;
        // cout << xa << ") ";
        // auto f = factorize(xa);
        // auto d = all_divisors(f);
        // for (auto const &i : d)
        //     cout << i << " ";
        // cout << endl;
        // cout << xb << ") ";
        // f = factorize(xb);
        // d = all_divisors(f);
        // for (auto const &i : d)
        //     cout << i << " ";
        // cout << endl;
        // cout << endl;
    }
}
