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

    string s;
    cin >> s;
    cin >> s;
    vector<pair<string,bool>> v(s.size(), mp("", false));
    rep(i,s.size()) {
        // cout << i << endl;
        auto cs = s.size() - i;
        int x = 0;
        if (cs%2) {x=1;}
        auto wat = (cs/2)+x;
        // cout << wat << endl;
        rep(j,v.size()) {
            if (v[j].second) {continue;}
            wat--;
            if (wat == 0) {
                v[j].first = s.substr(i).front();
                v[j].second = true;
                // cout << v[j].first << ":" << v[j].second << "=" << wat << endl;
                // for (auto w: v) {
                //     cout << w.first;
                // }
                // cout << endl;
            }
            // if (wat == 1) {j.first = s.substr(i).front(); j.second = true;}
            // if (j.second) {wat--;}
        }

        // rep(j,((cs/2)+x)) {
        //     if (j == (int)((cs/2)+x)-1 ) {v[j].first = s.substr(i).front(); v[j].second = true;}
        // }
        //
        // cout << (cs/2)+x << ": ";
        // cout << s.substr(i).front() << endl;
        // r[(cs/2)+x] = s.substr(i).front();
    }
    for (auto i : v) {
        cout << i.first;
    }
    cout << endl;
}
