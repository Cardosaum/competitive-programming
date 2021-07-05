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
    mullull m;
    while (cin >> n)
        m[n]++;
    ull cars = m[4];
    ull tmp = min({m[1], m[3]});
    cars += tmp;
    m[1] -= tmp;
    m[3] -= tmp;
    tmp = m[2] / 2;
    cars += tmp;
    m[2] -= tmp * 2;
    tmp = min({m[1] / 2, m[2]});
    cars += tmp;
    m[1] -= tmp * 2;
    m[2] -= tmp;
    cars += m[3];
    cars += m[2] / 2;
    cars += m[1] / 4;
    cars += m[2] % 2;
    cars += m[1] % 4;
    cout << cars << endl;
    // ull current = 0;
    // for (auto [k, v] : m){
    //     if (m[k] && k+current <= 0){m[k]--;current+=k;}
    //     else if (m[k]==0){current+=3;m[k]--;}
    // }
}
