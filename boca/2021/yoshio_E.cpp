const bool DEBUG = false;
#include <bits/stdc++.h>
using namespace std;

// quirino's (cf/cebolinha, at/edu) cool template v0.9 {{{
// Nice IO - Capable of printing vectors, sets, maps and pairs
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &a : v) is >> a; return is; }
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
  for (int i = 0; i < (int)v.size(); i++) os << (i?" ":"") << v[i]; return os; }
template <typename T> ostream &operator<<(ostream &os, set<T> v) {
  for (auto it = v.begin(); it != v.end(); it++) os << (it != v.begin() ? " " : "") << *it; return os; }
template <typename F, typename S> ostream &operator<<(ostream &os, pair<F, S> v) {
  os << v.first << " " << v.second; return os; }
template <typename K, typename V> ostream &operator<<(ostream &os, map<K, V> v) {
  bool f = true; for (auto [k, v] : v) { os << (f ? "" : "\n") << k << "\t\t" << v << endl; f = false; } return os; }
template <typename... A> void in(A &...a) { ((cin >> a), ...); }
template <typename... A> void out(A... a) { ((cout << a << " "), ...); cout << endl;}
template <typename... A> void print(A... a) { ((cout << a), ...); }

// Nice debugging - Colorful
#define var(x) "\033[33m[", #x, " \033[31m", x, "\033[33m]\033[32m "
template <typename... A> void db(A... a) { if (not DEBUG) return;
  cout << "\033[32m"; ((cout << (a)), ...); cout << "\033[0m" << endl; }
#define TEMPLATE if (not DEBUG) ios::sync_with_stdio(false), cin.tie(nullptr); db("Debug Mode Active --- Do not submit!");

// Nice abbreviations
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
using ll  = long long;

// Ordered set - order_of_key, find_by_order
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// }}} 

signed main() { TEMPLATE
  int n; in(n);

  queue<int> sub, des;
  for (int i = 0; i < n; i++) {
    int t, d; in(t, d);
    if (d == 0) sub.push(t);
    else des.push(t);
  }

  int t = -1, dir = 0;
  while (!sub.empty() || !des.empty()) {
    // Just continue
    if (!sub.empty() && dir == 0 && sub.front() < t) {
      if (sub.front() + 10 > t) 
        t = sub.front() + 10;
      sub.pop();
    } else if (!des.empty() && dir == 1 && des.front() < t) {
      if (des.front() + 10 > t) 
        t = des.front() + 10;
      des.pop();
    }

    // Get the smallest one
    else {
      if (sub.empty()) { // ninguem quer subir
        t = max(t, des.front()) + 10;
        des.pop();
        dir = 1;
      }
      else if (des.empty()) { // ninguem quer descer
        t = max(t, sub.front()) + 10;
        sub.pop();
        dir = 0;
      }
      else if (sub.front() < des.front()) { // subir antes
        t = max(t, sub.front()) + 10;
        sub.pop();
        dir = 0;
      }
      else {                                // descer antes
        t = max(t, des.front()) + 10;
        des.pop();
        dir = 1;
      }
    }
  }

  out(t);
}


