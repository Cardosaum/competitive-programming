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

    string s;
    map<char,int> original;
    map<char,int> random;
    rep(i,3) {
        cin >> s;
        // cout << s << s.size() << endl;
        if (i!=2) {
            rep(j,s.size()) {
                // cout << "j: " << j << "\ts[j]: " << s[j] << endl;
                original[s[j]]++;
            }
        } else {
            rep(j,s.size()) {
                random[s[j]]++;
            }
        }
    }

    if (original == random) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    // cout << (original == random) << endl;

    // cout << endl;
    // cout << "Original" << endl;
    // for (auto const& [key, val]: original) {
    //     cout << key << ": " << val << endl;
    // }
    // cout << endl;
    // cout << "Original" << endl;
    // for (auto const& [key, val]: random) {
    //     cout << key << ": " << val << endl;
    // }
}
