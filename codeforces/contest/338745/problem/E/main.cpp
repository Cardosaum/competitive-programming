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
#define rint(i, n) for (int i = 0; i < (int)(n); i++)
#define rull(i, n) for (ull i = 0; i < (ull)(n); i++)
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

ull points(ull k, deque<ull> &v_psum) {
    k = k - (k / 4);
    if ((v_psum.size() - 1 - k) > v_psum.size())
        return v_psum.back();
    else
        return v_psum.back() - v_psum[(v_psum.size() - 1 - k)];
}

int main() {
    SPEED;
    TESTS {
        ull n;
        cin >> n;
        vull me(n);
        vull you(n);
        for (auto &i : me)
            cin >> i;
        for (auto &i : you)
            cin >> i;
        sort(all(me));
        sort(all(you));
        ull s = 0;
        deque<ull> me_psum(n + 1);
        deque<ull> you_psum(n + 1);
        rull(i, n) {
            s += me[i];
            me_psum[i] = s;
        }
        s = 0;
        rull(i, n) {
            s += you[i];
            you_psum[i] = s;
        }
        me_psum.pop_back();
        you_psum.pop_back();
        ull more_contests = 0;
        while (points(n, me_psum) < points(n, you_psum)) {
            n++;
            more_contests++;
            me_psum.push_back(me_psum.back() + 100);
            you_psum.push_front(0);
        }
        cout << more_contests << endl;
    }
}
