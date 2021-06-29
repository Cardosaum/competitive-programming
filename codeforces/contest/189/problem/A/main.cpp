#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED                                                                  \
  ios_base::sync_with_stdio(false);                                            \
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
typedef map<char, int> mci;

typedef set<int>::iterator si_it;
typedef map<int, int>::iterator mii_it;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

[[maybe_unused]] const int INF = 1e9 + 7;
[[maybe_unused]] const int MOD = 1e9 + 7;
[[maybe_unused]] const int MAXN = 1e6 + 3;

ull cut(ull n, ull x, sull s) {
  if (n == 0) {
    return 1;
  } else if (n < x || s.find(n) == s.end()) {
    cout << "* " << n << ":" << x << " n not in set or x > n" << endl;
    return 0;
  }
  n = n - x;
  if (n < x) {
    ull tmp;
    for (auto i : s) {
      if (i < x) {
        tmp = max(i, tmp);
      }
    }
    x = tmp;
  }
  return cut(n, x, s);
}

int main() {
  SPEED;

  ull n;
  sull s;
  cin >> n;
  rep(i, 3) {
    ull x;
    cin >> x;
    s.ep(x);
  }

  cout << "CUT: " << cut(n, 5, s) << endl;
}
