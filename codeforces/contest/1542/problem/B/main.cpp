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

bool reduc(ull n, ull a, ull b, mullull dp) {
    if (n <= 0) {
        return false;
    } else if (dp[n] == 2) { // n is not in the set
        return false;
    }

    if (n - b == 1) {
        dp[n - b] = true;
        return true;
    } else if (n == a) {
        dp[n] = true;
        return true;
    } else {
    }
    bool r = false;
    if (dp[n] == 0) { // we need to compute
    }
}

int main() {
    SPEED;
    TESTS {
        ull n, a, b;
        cin >> n >> a >> b;
        mullull dp;
        reduc(n, a, b, dp);
        // if (n == 1) {
        //     YES;
        // } else if (b == 1) {
        //     YES;
        // } else if ((n % b) == 1) {
        //     YES;
        // } else if ((n / a) % a == 0) {
        //     YES;
        // } else {
        //     NO;
        // }
    }
}
