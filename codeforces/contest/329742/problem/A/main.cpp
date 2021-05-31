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

int main() {
    SPEED;

    vc v;
    int n,q,l,r;
    cin >> n;
    cin >> q;

    rep(i,n) {
        char c;
        cin >> c;
        v.pb(c);
    }

    rep(i,q) {
        map<char,int> dict;
        cin >> l;
        cin >> r;
        // cout << l << " " << r << endl;
        for (auto j = l-1; j <= r-1; j++) {
        // rep(j,v.size()) {
            // if (j < l-1 || j > r-1) {continue;}
            // cout << j << endl;
            dict[v[j]]++;
        }

        int odd {0};
        for (auto const& [key, value]: dict) {
            if (value%2) {odd++;}
        }
        if (((r-l)+1)%2 && odd == 1) {cout << "Sim" << endl;}
        else if (!(((r-l)+1)%2) && odd == 0) {cout << "Sim" << endl;}
        else {cout << "Nao" << endl;}
    }

}
