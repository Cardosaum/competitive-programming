#include <bits/stdc++.h>
#include <cmath>
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

ull num_divisors(mullull f) {
    ull divisors = 1;
    for (auto const &[k, v] : f)
        divisors *= (v + 1);
    return divisors;
}

sull all_divisors(ull n) {
    sull d;
    for (ull i = 1; i <= n; i++)
        if (n % i == 0)
            d.insert(i);
    return d;
}

ull delta_divisors(sull all_divisors) {
    ull a = 0;
    ull b = 0;
    ull delta = INF;
    for (auto const &i : all_divisors) {
        if (!a) {
            a = i;
            continue;
        }
        b = i;
        delta = min(delta, (b - a));
        a = b;
    }
    return delta;
}

bool ok(ull n, ull d, map<ull, pair<ull, ull>> &dp) {
    if (dp[n].first == 0 && dp[n].second == 0) {
        auto f = factorize(n);
        auto divisors = num_divisors(f);
        dp[n].first = divisors;
        if (divisors < 4) {
            return false;
        } else {
            dp[n].second = delta_divisors(all_divisors(n));
            return dp[n].second >= d;
        }
    } else {
        return dp[n].first >= 4 && dp[n].second >= d;
    }
}

int main() {
    SPEED;
    map<ull, pair<ull, ull>> dp;
    rull(j, 3000) {
        for (ull i = 1; i <= 10000; i++) {
            cout << i << ":" << ok(i, 2, dp) << endl;
        }
    }

    // TESTS {
    //     ull d;
    //     cin >> d;
    //     ull number = 6;
    //     while (1) {
    //         // cout << "=> " << number << endl;
    //         if (ok(number, d, dp)) {
    //             cout << number << endl;
    //             break;
    //         }
    //         number++;
    //     }
    // }
}
