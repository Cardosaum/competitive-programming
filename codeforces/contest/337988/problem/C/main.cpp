#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
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

// ull least_factor(ull n) {
//     ull x = 2;
//     ull limit = (ull)sqrt(n);
//     while (x <= limit) {
//         if (n % x == 0)
//             return x;
//         else
//             x++;
//     }
//     return n;
// }

// mullull factorize(ull n) {
//     mullull factors;
//     while (n != 1) {
//         ull factor = least_factor(n);
//         n /= factor;
//         factors[factor]++;
//     }
//     return factors;
// }

// ull num_divisors(mullull &f) {
//     ull divisors = 1;
//     for (auto const &[k, v] : f)
//         divisors *= (v + 1);
//     return divisors;
// }

// sull all_divisors(mullull &factorized) {
//     sull d;
//     vector<pair<ull, ull>> factors;
//     for (auto const &[k, v] : factorized)
//         factors.emplace_back(mp(k, v));
//     ull nfactors = factors.size();
//     vull f(nfactors);
//     while (1) {
//         ull s = 1;
//         vull tmp;
//         rull(i, nfactors) { tmp.emplace_back(pow(factors[i].first, f[i])); }
//         for (auto const &i : tmp)
//             s *= i;
//         d.insert(s);
//         ull I = 0;
//         while (1) {
//             f[I]++;
//             if (f[I] <= factors[I].second) {
//                 break;
//             }
//             f[I] = 0;
//             I++;
//             if (I >= nfactors) {
//                 goto all_divisors_end;
//             }
//         }
//     }
// all_divisors_end:
//     return d;

//     // for (ull j = 1; j * j <= n; j++) {
//     //     if (n % j == 0) {
//     //         d.insert(j);
//     //         if (j != (n / j))
//     //             d.insert(n / j);
//     //     }
//     // }
// }

// ull delta_divisors(sull all_divisors) {
//     ull a = 0;
//     ull b = 0;
//     ull delta = INF;
//     for (auto const &i : all_divisors) {
//         if (!a) {
//             a = i;
//             continue;
//         }
//         b = i;
//         delta = min(delta, (b - a));
//         a = b;
//     }
//     return delta;
// }

// bool ok(ull n, ull d, map<ull, pair<ull, ull>> &dp) {
//     if (dp[n].first == 0 && dp[n].second == 0) {
//         auto f = factorize(n);
//         auto divisors = num_divisors(f);
//         dp[n].first = divisors;
//         if (divisors < 4) {
//             return false;
//         } else {
//             dp[n].second = delta_divisors(all_divisors(f));
//             return dp[n].second >= d;
//         }
//     } else {
//         return dp[n].first >= 4 && dp[n].second >= d;
//     }
// }

ull answer(ull d, sull &prime) {
    ull a = 0;
    ull b = 0;
    for (auto const &i : prime) {
        if (d <= i - 1 && a == 0)
            a = i;
        else if (d <= i - a && a != 0) {
            b = i;
            break;
        }
    }
    return a * b;
}

int main() {
    SPEED;
    // map<ull, pullull> dp;
    auto prime = primes(100'000);

    // auto f = factorize(329847198123);
    // for (auto const &i : all_divisors(f))
    //     cout << i << " ";
    // cout << endl;
    //
    // std::random_device rd;  // obtain a random number from hardware
    // std::mt19937 gen(rd()); // seed the generator
    // std::uniform_int_distribution<> distr(1, 10000); // define the range
    // rull(j, 3000) {
    //     ull delta = distr(gen);
    //     for (ull i = 6; i <= INF; i++) {
    //         if (ok(i, delta, dp)) {
    //             cout << i << ":" << delta << endl;
    //         }
    //         cout << delta << ") " << i << ": " << dp[i].first << "="
    //              << dp[i].second << endl;
    //     }
    // }

    // for (ull i = 1; i <= 10'000; i++) {
    //     cout << i << ": " << answer(i, prime) << endl;
    //     // for (ull j = 1; j <= INF; j++) {
    //     //     // cout << j << ") ";
    //     //     // for (auto const &[k, v] : factorize(j))
    //     //     //     cout << k << ":" << v << " ";
    //     //     // cout << endl;
    //     //     if (ok(j, i, dp)) {
    //     //         cout << i << ":" << j << endl;
    //     //         break;
    //     //     }
    //     // }
    // }
    // cout << endl;

    TESTS {
        ull d;
        cin >> d;
        cout << answer(d, prime) << endl;
        // cout << a * b << " " << a << ":" << b << endl;
        // cout << a * b << endl;
    }
}
