#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED                                                                  \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr)
#define endl '\n'
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<string> vs;
typedef vector<ii> vii;
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

int main() {
    SPEED;
    ull t;
    cin >> t;
    while (t--) {
        ull n;
        cin >> n;
        string s;
        while (n--) {
            char a;
            cin >> a;
            s.pb(a);
        }
        bool is_palindrome = true;
        rep(i, (s.size() / 2)) {
            if ((max(s[i], s[s.size() - i - 1]) -
                     min(s[i], s[s.size() - i - 1]) !=
                 0) &&
                (max(s[i], s[s.size() - i - 1]) -
                     min(s[i], s[s.size() - i - 1]) !=
                 2)) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            YES;
        } else {
            NO;
        }
    }
}
