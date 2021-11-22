// time-limit: 2000
// problem-url: https://codeforces.com/group/nituVTsHQX/contest/355422/problem/D
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
  struct Player {
    ull victories;
    ull matches;
    sull win_against;
    sull lose_against;
  };
  map<ull, Player> m;
  rull(i, ((n * (n - 1)) / 2) - 1) {
    ull x, y;
    cin >> x >> y;
    m[x].matches++;
    m[y].matches++;
    m[x].victories++;
    m[x].win_against.insert(y);
    m[y].lose_against.insert(x);
  }
  ull p1 = 0;
  ull p2 = 0;
  vector<pullull> s;
  for (auto const &[k, v] : m) {
    if (!p1 && v.matches == n - 2)
      p1 = k;
    else if (!p2 && v.matches == n - 2)
      p2 = k;
    else
      s.push_back(mp(k, v.victories));
  }

  sort(s.begin(), s.end(),
       [](const pullull &a, const pullull &b) { return a.second > b.second; });

  // cout << p1 << " : " << p2 << endl;
  // cout << endl;
  bool p1_wins = true;
  for (auto const &i : s) {
    if (m[p1].win_against.find(i.first) != m[p1].win_against.end() &&
        m[p2].lose_against.find(i.first) != m[p2].lose_against.end())
      break;
    else if (m[p2].win_against.find(i.first) != m[p2].win_against.end() &&
             m[p1].lose_against.find(i.first) != m[p1].lose_against.end()) {
      p1_wins = false;
      break;
    }
    // cout << i.first << ": " << i.second << endl;
  }
  // cout << endl;
  if (p1_wins)
    cout << p1 << " " << p2 << endl;
  else
    cout << p2 << " " << p1 << endl;
}
