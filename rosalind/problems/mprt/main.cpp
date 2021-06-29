#include <bits/stdc++.h>
#include <regex>
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

int main(int argc, char** argv) {
    SPEED;
    if (argc != 2) {return 1;}

    string file_name = argv[1];
    ifstream cin {file_name};

    file_name.erase(file_name.find(".fasta"), 7);

    string f;
    string s {""};
    while (getline(cin, f)) {
        if (f[0] == '>') {continue;}
        s += f;
    }

    regex r {"(?=(N[^P][ST][^P]))."};
    for (sregex_iterator i = sregex_iterator(all(s), r); i != sregex_iterator(); i++) {
        if (i == sregex_iterator(all(s), r)) {cout << file_name << endl;}
        smatch m = *i;
        cout << m.position()+1 << " ";
    }
    cout << endl;
}
