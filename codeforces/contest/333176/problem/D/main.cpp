#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl '\n'
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
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
typedef pair<int,int> ii;
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
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<char,int> mci;

typedef set<int>::iterator si_it;
typedef map<int,int>::iterator mii_it;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

[[maybe_unused]] const int INF = 1e9 + 7;
[[maybe_unused]] const int MOD = 1e9 + 7;
[[maybe_unused]] const int MAXN = 1e6 + 3;

int main() {
    SPEED;

    ull n;
    set<ull> s;
    cin >> n;
    while (cin >> n) {
        if (n == 1) {cout << 1 << endl;return 0;}
        s.ep(n);
    }

    ull f = 0;
    for (auto const& i: s) {
        bool found = true;
        for (auto const& j: s) {
            if (j%i || i > j) {found = false; break;}
            // cout << j << ":" << i << "=" << j%i << endl;
        }
        if (found) {f = i; break;}
    }
    if (f) {
        cout << f << endl;
    } else {
        cout << -1 << endl;
    }
}
