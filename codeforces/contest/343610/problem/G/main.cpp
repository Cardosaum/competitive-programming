#include <bits/stdc++.h>
#include <iterator>
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

void sieve(ull lim, vull &divisors, sull &primes) {
    divisors[1] = 1;
    for (ull i = 2; i <= lim; i++) {
        if (divisors[i] == 0)
            divisors[i] = i, primes.insert(i);
        for (ull j : primes) {
            if (j > divisors[i] or i * j > lim)
                break;
            divisors[i * j] = j;
        }
    }
}

int main() {
    // SPEED;
    vull divisors(MAXN + 3);
    sull primes;
    sieve(MAXN, divisors, primes);
    ull a, b, k;
    cin >> a >> b >> k;
    k--;
    ull l = 1;
    ull min_prime = MAXN + 3;
    ull max_prime = 0;

    for (auto it = primes.begin(); it != primes.end(); it++) {
        if (a > *it)
            continue;
        else if (*std::next(it, k) > b ||
                 (ull)std::distance(primes.begin(), it) > primes.size())
            break;
        if (k) {
            l = max(l, (*std::next(it, k) - *it) + 1);
        } else {
            l = max(l, *it - max(*std::prev(it), a));
        }
        // cout << l << ":" << *std::next(it, k) << ":" << *it << ", ";
        min_prime = min(min_prime, *it);
        max_prime = max(max_prime, *std::next(it, k));
    }

    // cout << endl;
    // cout << k << endl;
    // cout << endl;
    // cout << min_prime << ":" << max_prime << " ; " << a << ":" << b << endl;

    l = k ? l + max(min_prime - a, b - max_prime) : l + b - max_prime;
    l <= b - a + 1 ? cout << l << endl : cout << -1 << endl;
}
