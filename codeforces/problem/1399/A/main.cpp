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
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;
typedef istringstream iss;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

[[maybe_unused]] const int INF = 1e9 + 7;
[[maybe_unused]] const int MOD = 1e9 + 7;
[[maybe_unused]] const int MAXN = 1e6 + 3;

vi& mv(vi& v);
bool test(const vi& v) {
    int a,b;
    bool ok {true};
    rep(i,v.size()) {
        if (!i) {a = v[i];continue;}
        if (i==(int)v.size()) {break;}
        a = v[i-1];
        b = v[i];
        if (b-a > 1) {ok = false;break;}
        // cout << "a: " << a << " ";
        // cout << "b: " << b << endl;
    }
    // cout << "ok: " << ok << endl;
    return ok;
}

int main() {
    // SPEED;

    int n;
    cin >> n;
    rep(i,n) {
        // cout << i << ": ";

        int m;
        cin >> m;

        vi v;
        rep(j,m) {
            int x;
            cin >> x;
            v.pb(x);
        }
        sort(all(v));
        while (test(v) && v.size() != 1) {
            v.erase(v.begin());
        }

        if (v.size() == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        // cout << endl;
    }
}

