#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr)
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

mii primes(int limit) {
    // find all primes in interval [2, limit] (inclusive)
    mii p;
    mii np;
    for (int i = 2; i < (limit+1); i++) {
        if (np.find(i) == np.end()) {
            p[i] = i;
            for (auto j = i; j < (limit+1); j+=i) {
                np[j] = j;
            }
        }
    }
    return p;
}

int main() {
    SPEED;

    int n,m;
    cin >> n >> m;
    mii p {primes(m)};
    auto next {false};
    auto present {false};
    if (p.find(m) == p.end()) {present = false;}
    for (auto const& [k, v]: p) {
        if (n == v) {next = true;continue;}
        if (next) {if(m == v) {present=true;} break;}
    }

    if (present) {cout << "YES" << endl;}
    else {cout << "NO" << endl;}
}
