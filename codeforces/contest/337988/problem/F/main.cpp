#include <bits/stdc++.h>
#include <ostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

#define all(v) v.begin(), v.end()
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

int fake_judge(int l, int r, vi &v) {
    l--;
    r--;
    try {
        int s = 0;
        for (int i = l; i <= r; i++)
            s += v[i];
        return s;
    } catch (...) {
        return -1;
    }
}

vi load_fake() {
    vi v;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Vector: ";
    for (auto const &i : v)
        cout << i << " ";
    cout << endl;
    return v;
}

int main() {
    // int n, t, k;
    // cin >> n >> t >> k;

    // int l = 1;
    // int r = n / 2;
    // int zeros = 0;

    // int ith = 0;
    auto v = load_fake();
    int n;
    n = (int)v.size();
    int l = 1;
    int r = n / 2;
    int zeros = 0;
    int k = 7;
    while (n > 1) {
        // ith++;
        // if (ith > 5)
        //     break;
        int s;
        cout << "? " << l << " " << r << " => (n): " << n << endl;

        // cout << "? " << l << " " << r << endl;
        // cout.flush();
        // cout << flush;
        // cin >> s;

        s = fake_judge(l, r, v);
        if (s == -1)
            break;

        // n -= r - l + 1;
        // get how many zeros in interval
        int tmp_zeros = r - l + 1 - s;
        if (tmp_zeros >= k) {
            // keep left side of array
            n = r - l + 1;
            r = l + n / 2;
        } else {
            // search right side
            zeros += tmp_zeros;
            l = r + 1;
            r = l + ((n - l + 1) / 2);
            n = r - l + 1;
            if (n <= 1) {
                l = max(l, r);
                r = l;
            }
        }
    }
    // cout << endl;
    // cout << "FOUND: " << l << " " << r << " " << n << endl;
    // cout << min(l, r) << endl;
    cout << "* " << l << " " << r << " => (n): " << n << endl;
    cout << "! " << min(l, r) << endl;
    cout.flush();
    cout << flush;

    // rull(i, 20) {
    //     if (l > r)
    //         break;
    //     cout << i << ") " << l << ":" << r << " = " << n << " ; " << s <<
    //     endl; cout.flush();

    //     if (k > r-l+1-s) {
    //         l = r + 1;
    //         r = l + n;
    //     }
    // }
    // cout << "! " << n << endl;
}
