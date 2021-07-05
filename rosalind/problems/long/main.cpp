#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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
#define rint(i, n) for (int i = 0; i < (int)(n); i++)
#define rull(i, n) for (ull i = 0; i < n; i++)
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

string overlap(string a, string b) {
    string s = "";
    auto b_size = b.size();
    auto a_size = a.size();
    if (a_size > b_size)
        rull(i, a_size - b_size + 1) if (a.substr(i, b_size) ==
                                         b) return "SUBSTRING";
    rull(i, a.size()) {
        auto a_sub = a.substr(i);
        auto a_sub_size = a_sub.size();
        if (a_sub == b.substr(0, a_sub_size) && a_sub_size >= (b_size - 1) / 2)
            return a.substr(0, i) + b;
    }
    return s;
}

mss read_fasta() {
    string s, gene;
    mss genes;
    while (cin >> s) {
        if (s.front() == '>') {
            gene = s.substr(1);
            genes[gene] = "";
        } else
            genes[gene] += s;
    }
    return genes;
}

int main() {
    SPEED;

    ofstream out;
    out.open("result.txt");

    auto genes = read_fasta();
    vs v;
    for (auto [k, s_] : genes)
        v.pb(s_);
    auto seq = v.back();
    v.pop_back();
    ull COUN = 0;
    while (!v.empty()) {
        cout << ++COUN << ") " << seq << endl;
        // cout << "VECTOR: ";
        for (auto i : v)
            cout << i << endl;
        for (ull i = v.size(); i-- > 0;) {
            auto tmp = overlap(seq, v[i]);
            if (tmp == "SUBSTRING") {
                v.erase(v.begin() + i);
                break;
            }
            if (!tmp.empty()) {
                seq = tmp;
                v.erase(v.begin() + i);
                break;
            }
            tmp = overlap(v[i], seq);
            if (!tmp.empty()) {
                seq = tmp;
                v.erase(v.begin() + i);
                break;
            }
        }
    }
    cout << "FINAL: " << endl;
    cout << seq << endl;
    return 0;
}
