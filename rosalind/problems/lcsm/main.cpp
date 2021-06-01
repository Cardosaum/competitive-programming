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


// // credit: https://stackoverflow.com/a/49710675/10719703
// std::string lcs( std::string a, std::string b )
// {
//     if( a.empty() || b.empty() ) return {} ;

//     std::string current_lcs = "";

//     for(int i=0; i < (int)a.length(); i++) {
//         size_t fpos = b.find(a[i], 0);
//         while(fpos != std::string::npos) {
//             std::string tmp_lcs = "";
//             tmp_lcs += a[i];
//             for (int x = (int)fpos+1; x < (int)b.length(); x++) {
//                 tmp_lcs+=b[x];
//                 size_t spos = a.find(tmp_lcs, 0);
//                 if (spos == std::string::npos) {
//                     break;
//                 } else {
//                     if (tmp_lcs.length() > current_lcs.length()) {
//                         current_lcs = tmp_lcs;
//                     }
//                 }
//             }
//             fpos = b.find(a[i], fpos+1);
//         }
//     }
//     return current_lcs;
// }

int main() {
    SPEED;

    vs seqs;
    string s;
    string seq;
    auto new_fasta {false};
    ll fasta_counter {0};

    // read fasta
    while (cin >> s) {
        if (s[0] == '>') {
            new_fasta = true;
            fasta_counter++;
            continue;
        }  else if (new_fasta && !seq.empty() && fasta_counter > 1) {
            seqs.pb(seq);
            seq.clear();
        }
        seq += s;
    }
    seqs.pb(seq);

    // find longest substring
    s.clear();
    for (int i = 0; i < (int)seqs.size(); i++) {
        if (s.empty()) {s = seqs[i];}
        s = lcs(s,seqs[i]);
    }
    cout << s << endl;
}
