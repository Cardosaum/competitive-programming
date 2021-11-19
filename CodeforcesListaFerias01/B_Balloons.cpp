// time-limit: 1000
// problem-url: https://codeforces.com/group/nituVTsHQX/contest/355422/problem/B

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr)
#define endl '\n'
#define TESTS                                                                  \
  ull T;                                                                       \
  cin >> T;                                                                    \
  while (T--)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define M_PIl 3.141592653589793238462643383279502884L
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

int main() {
  SPEED;
  ull n;
  cin >> n;
  if (n < 2) {
    cout << -1 << endl;
    return 0;
  }
  multiset<pair<ull, ull>> s;
  pullull andrew = mp(0, 0);
  pullull grigory = mp(0, 0);
  rull(i, n) {
    ull j;
    cin >> j;
    s.insert(mp(j, i));
  }
  for (auto const &i : s) {
    // cout << "I: " << i.first << ", " << i.second << endl;
    if (andrew.first == 0)
      andrew = i;
    else
      grigory.first += i.first;
  }
  if (andrew.first == grigory.first) {
    cout << -1 << endl;
  } else {
    cout << 1 << endl;
    cout << andrew.second + 1 << endl;
  }
}
