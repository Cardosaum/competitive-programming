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
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<long long int> vll;
typedef long double ld;
typedef istringstream iss;
typedef set<int> si;
typedef set<char> sc;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<char,int> mci;
typedef map<int,char> mic;

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
    map<char,map<int,int>> seqs;
    sc letters {'A', 'C', 'T', 'G'};
    auto new_fasta {false};

    string sequence;
    ul sequence_counter {0};
    while (cin >> s) {
        if (s[0] == '>') {
            sequence_counter++;
            new_fasta = true;
            continue;
        }
        if (new_fasta && !sequence.empty() && sequence_counter > 1) {
            // cout << "====" << endl;
            // cout << sequence << endl;
            // cout << "====" << endl;

            rep(i,sequence.size()) {
                sc letter {sequence[i]};
                sc diff;
                set_difference(letters.begin(), letters.end(), letter.begin(), letter.end(), inserter(diff, diff.end()));
                for (auto const& j: diff) {seqs[j].try_emplace(i, 0);}
                seqs[sequence[i]][i]++;
            }
            sequence.clear();
            new_fasta = false;
        }
        sequence += s;
    }
    // cout << "====" << endl;
    // cout << sequence << endl;
    // cout << "====" << endl;
    rep(i,sequence.size()) {
        sc letter {sequence[i]};
        sc diff;
        set_difference(letters.begin(), letters.end(), letter.begin(), letter.end(), inserter(diff, diff.end()));
        for (auto const& j: diff) {seqs[j].try_emplace(i, 0);}
        seqs[sequence[i]][i]++;
    }

    // cout << endl;
    // cout << endl;
    // cout << "OIA AQUI" << endl;
    // cout << endl;

    // print consensus
    map<int,pair<int,char>> m;
    for (auto const& [key, value]: seqs) {
        for (auto const& [i, j]: value) {
            m.te(i,mp(j,key));
            if (j > m[i].first) {m[i] = mp(j,key);}
        }
    }

    // print profile
    string f;
    for (auto const& [key, value]: seqs) {
        s.clear();
        s.pb(key);
        s += ": ";
        for (auto const& [i, j]: value) {
            m.te(i,mp(j,key));
            if (j > m[i].first) {m[i] = mp(j,key);}
            s += to_string(j);
            s += " ";
        }
        s += '\n';
        f += s;
    }

    for (auto const& [indx, val]: m) {
        cout << val.second;
    }
    cout << endl;

    cout << f << endl;

}
