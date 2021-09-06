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
    SPEED;
    ull n, k;
    cin >> n >> k;
    vull divisors(n + 1);
    sull primes;
    sieve(n, divisors, primes);
    ull found = 0;
    for (auto it = primes.begin(); it != std::prev(primes.end()); it++) {
        if (primes.find(*it + *(std::next(it)) + 1) != primes.end())
            found++;
        if (found >= k)
            break;
    }
    if (found >= k) {
        YES;
    } else {
        NO;
    }
}
