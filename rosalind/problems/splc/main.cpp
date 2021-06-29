#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(nullptr)
#define endl '\n'
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
typedef pair<int, int> ii;
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
typedef map<int, int> mii;
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

string dna_to_aa(string seq) {
  mss table{{"AAA", "K"},    {"AAC", "N"}, {"AAG", "K"},    {"AAT", "N"},
            {"ACA", "T"},    {"ACC", "T"}, {"ACG", "T"},    {"ACT", "T"},
            {"AGA", "R"},    {"AGC", "S"}, {"AGG", "R"},    {"AGT", "S"},
            {"ATA", "I"},    {"ATC", "I"}, {"ATG", "M"},    {"ATT", "I"},
            {"CAA", "Q"},    {"CAC", "H"}, {"CAG", "Q"},    {"CAT", "H"},
            {"CCA", "P"},    {"CCC", "P"}, {"CCG", "P"},    {"CCT", "P"},
            {"CGA", "R"},    {"CGC", "R"}, {"CGG", "R"},    {"CGT", "R"},
            {"CTA", "L"},    {"CTC", "L"}, {"CTG", "L"},    {"CTT", "L"},
            {"GAA", "E"},    {"GAC", "D"}, {"GAG", "E"},    {"GAT", "D"},
            {"GCA", "A"},    {"GCC", "A"}, {"GCG", "A"},    {"GCT", "A"},
            {"GGA", "G"},    {"GGC", "G"}, {"GGG", "G"},    {"GGT", "G"},
            {"GTA", "V"},    {"GTC", "V"}, {"GTG", "V"},    {"GTT", "V"},
            {"TAA", "STOP"}, {"TAC", "Y"}, {"TAG", "STOP"}, {"TAT", "Y"},
            {"TCA", "S"},    {"TCC", "S"}, {"TCG", "S"},    {"TCT", "S"},
            {"TGA", "STOP"}, {"TGC", "C"}, {"TGG", "W"},    {"TGT", "C"},
            {"TTA", "L"},    {"TTC", "F"}, {"TTG", "L"},    {"TTT", "F"}};

  string aa{""};

  for (ull i = 0; i < seq.size(); i += 3) {
    auto s = seq.substr(i, 3);
    if (table[s] == "STOP") {
      break;
    }
    aa += table[s];
  }
  return aa;
}

int main() {
  SPEED;

  string gene;
  map<string, string> genes;
  string s;
  ull total_genes = 0;
  while (cin >> s) {
    if (s.front() == '>') {
      total_genes++;
      gene = s.substr(1);
      genes[gene] = "";
    } else {
      genes[gene] += s;
    }
  }

  for (auto [k1, v1] : genes) {
    ull matches = 0;
    for (auto [k2, v2] : genes) {
      if (v1.find(v2) != v1.npos) {
        matches++;
      }
    }
    if (matches == total_genes) {
      gene = k1;
      break;
    }
  }

  for (auto [k, v] : genes) {
    if (v == genes[gene]) {
      continue;
    }
    genes[gene].erase(genes[gene].find(v), v.size());
  }

  cout << dna_to_aa(genes[gene]) << endl;
}
