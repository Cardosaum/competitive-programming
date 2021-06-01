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
typedef set<string> ss;
typedef set<char> sc;
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
    getline(cin, s);
    // s.pop_back();
    sc v {'A', 'E', 'I', 'O', 'U', 'Y'};
    sc c {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'};
    transform(all(s), s.begin(), [](unsigned char x) {return toupper(x);});

    s.erase(
        remove_if(
            all(s),
            [v, c](unsigned char x) {
                return ((v.find(x) == v.end()) && (c.find(x) == c.end()));
            }
        ),
        s.end());

    if (v.find(s.back()) == v.end()) {cout << "NO" << endl;}
    else {cout << "YES" << endl;}
}
