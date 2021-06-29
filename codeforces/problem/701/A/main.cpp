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

bool all_used(set<pair<int,bool>> const& s) {
    int n {0};
    for (auto i: s) {if (i.second) {n++;}}
    return n == (int)s.size() ? true : false;
}

int main() {
    SPEED;

    int x;
    cin >> x;
    int n;
    map<int,set<pair<int,bool>>> m;
    int s {0};
    int j {1};
    while (cin >> n) {
        cout << n << ":" << j << endl;
        s += n;
        m[n].ep(mp(j,false));
        j++;
    }
    int t {s/x};
    // cout << t << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        // cout << it->first << endl;
        while (!all_used(it->second)) {
            for (auto j = it->second.begin(); j != it->second.end(); j++) {
                if (j->second) {continue;}
                cout << j->first << " ";
                j->second = true;
            }
            cout << it->second << " ";
            auto b = m[t-it->first].begin();
            cout << *b << endl;
            it->second.erase(a);
            m[t-it->first].erase(b);
        }
    }
}
