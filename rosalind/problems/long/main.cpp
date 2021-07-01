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

// string overlap(string a, string b) {
//     string s = "";
//     rull(i, b.size()) {
//         // cout << i << ": " << endl;
//         // cout << a.substr(i) << endl;
//         // cout << b.substr(0, a.substr(i).size()) << endl;
//         if (s.empty() && a.substr(0, i).size() + b.size() >= (a.size() / 2)
//         &&
//             a.substr(i) == b.substr(0, a.substr(i).size())) {
//             s = a.substr(0, i);
//             s += b;
//             break;
//         } else if (a.substr(i, b.size()) == b) {
//             return a;
//         } else if (a.substr(i).size() < (a.size() / 2))
//             break;
//     }
//     return s;
// }

string overlap(string a, string b) {
    // cout << a << "\n" << b << endl;
    string s = "";
    // ull matches = 0;
    auto b_size = b.size();
    // auto a_size = a.size();
    rull(i, a.size()) {
        // if (matches >= b_size)
        //     break;
        // // else if (i > ((i + b.size()) / 2) + 1)
        // //     break;

        auto a_sub = a.substr(i);
        auto a_sub_size = a_sub.size();
        if (a_sub == b.substr(0, a_sub_size) && a_sub_size >= (b_size - 1) / 2)
            return a.substr(0, i) + b;
        // else if (a[i] == b[matches])
        //     matches++;
        // else
        //     matches = 0;

        // cout << i << ":" << matches << ") " << a[i] << ":" << b[matches] <<
        // endl
        //      << a.substr(i, 80) << endl
        //      << b.substr(0, 80) << endl
        //      << endl;

        // if (matches == b_size)
        //     return a;
    }
    // cout << endl;
    // cout << "> " << matches << endl;
    // if (!matches)
    //     return s;
    // else if (matches >= b_size / 2)
    //     s = a + b.substr(matches);
    return s;
}

int main() {
    SPEED;

    ofstream out;
    out.open("result.txt");

    mss genes;
    string gene;
    // string s1 = "AAAACGATATCAAGCATATGCGGGAACCGTTTCTTCCGTTGGAGGATCTGGAATTAAG"
    //             "GAGCAGACCGCG"
    //             "CCACACAAATCCCAGAAAAATCGAACCGAAGTCCATTGTAAACGCTTCAGTATGTCAG"
    //             "CAACCATAAGGA"
    //             "TTGCAGATTGTGTGATTGTGTGGACATATTGGTATCCGGAGAAACACGATCCACTTGA"
    //             "CATCCTTGGCTG"
    //             "CATGGGACTGTGTATCCCCCTTCAAGTAACTACGTCCGATTTATGTCAAGAATCAGGG"
    //             "CAAGTGCCTCGA"
    //             "TGCGGCCGATACCCAGAGAATGCAAAGAAGGGGCGAAGAACAATGAGCCAATAACCCA"
    //             "TGTAAGACATTT"
    //             "AGAGTTAAGACCAAGAAAAGGATGGTGCACAAATGTGCCCGTCTTGACTCTCAGTCAA"
    //             "GGCCCGCGATTG"
    //             "GAGAATGGCAGACTGATAAGAAGAGTTACCGGCACGAATGTCAGTCTTCATGTGCGGG"
    //             "ATTAACCCAGCG"
    //             "ACATCAGACTCTATGGGAGTAGACTACTGGTAACAATCGATCAGCCCTTCTCTGGGTG"
    //             "CGTATCCTTTAT"
    //             "GCCGTATACCTTACGCCACGGCCACTAACACAATTATGTATTGATGCCTCACACGTTT"
    //             "CGATGTGTGATA"
    //             "TCTCCGGAACTCCAGCTGGGAAGCGTACACTTTCAGTTGTCATTCAGCGCTACCGCAA"
    //             "CCCCCAAGGCTC"
    //             "CAGGCTGAGTACTGGCTTGTAGGCACCAAGATCAAGTCACAGCTAGTTTCTACGAACG"
    //             "ACTCGATAGCGA"
    //             "TCTGCAAAAAGGGAGTCGAATTCCTACGCTGGCATTTTGGATCTCCTAAAAGAAGTAG"
    //             "AACCTCCTTGTT"
    //             "GTGCTTAGGCAGCAGCTACTCAAGTTGCTGCGCGTAGCGGAGCGATTGGATGATACAA"
    //             "AATCATGAGGAG"
    //             "ACGTTCTCTTATTCTTGCACTGTACCGGACACGAATAATTTAAGTGCTTTCAGTCGAA"
    //             "CGTATTGCAGCC"
    //             "TCA";
    // string s2 = "CATAAATGTTGTACGCGAGTACCAGATCTGACCTTTGGCAAGCCGCAAGTTGAACACG"
    //             "TTTGTGCATACC"
    //             "GTTACATTACGAGGCTTGTAGTGCGAGTAAGATTGTAAACTTGTATCGAGGGTCGCTA"
    //             "CCAGAGCCGGAT"
    //             "GCGGGGATAAACAATCGTTTTAACCAAACTGCCATTGGATGAATAGACCATACAGGCC"
    //             "CGCGAGAGCCTC"
    //             "CCACTCCCAGTACAATCGCAGTATAAACTCTTTGACCGAGGTATGGGGTATTTGCTGA"
    //             "CGCACTCGCACA"
    //             "CAAAGGCAAGCAAGAGACACACCCATAGACCGGTCCAGCGGCTCTCCGGCTGTAAGAC"
    //             "CTCGGTGGGTAC"
    //             "CTCTCTCACCGAAAGCAGCGCTTCTTAGGCGACATTTTAACCGATACACGGAAGAAGT"
    //             "GTTTACCCTACT"
    //             "TGCAGTTCGGTGCCGAAATCAGTCTGAGAAATCGCTATGCCTACTGAAAATGTAGCTA"
    //             "AATTACAGCAGT"
    //             "CGCTAATCCAACCGGAATACGATTTGATTAGGGTGTCTCGTCTTTTGTGACCCAGGTA"
    //             "GGTTCGCGATTA"
    //             "ACAAATCACAGAACCGTCAGAGTCGCGACTCCATTAGTGTATCTATGTAACAGTGTAA"
    //             "GGCGGCTGGGAT"
    //             "CCCGCACCTCAAAAACGATATCAAGCATATGCGGGAACCGTTTCTTCCGTTGGAGGAT"
    //             "CTGGAATTAAGG"
    //             "AGCAGACCGCGCCACACAAATCCCAGAAAAATCGAACCGAAGTCCATTGTAAACGCTT"
    //             "CAGTATGTCAGC"
    //             "AACCATAAGGATTGCAGATTGTGTGATTGTGTGGACATATTGGTATCCGGAGAAACAC"
    //             "GATCCACTTGAC"
    //             "ATCCTTGGCTGCATGGGACTGTGTATCCCCCTTCAAGTAACTACGTCCGATTTATGTC"
    //             "AAGAATCAGGGC"
    //             "AAGTGCCTCGATGCGGCCGATACCCAGAGAATGCAAAGAAGGGGCGAAGAACAATGAG"
    //             "CCAATAACCCAT"
    //             "GTAAGACATT";
    // cout << overlap(s1, s2) << endl;
    // cout << overlap(s2, s1) << endl;
    // return 0;
    string s;
    while (cin >> s) {
        if (s.front() == '>') {
            gene = s.substr(1);
            genes[gene] = "";
        } else
            genes[gene] += s;
    }

    vs v;
    for (auto [k, s_] : genes)
        v.pb(s_);
    // for (auto i : v)
    //     out << i << endl;
    // return 0;
    bool used_goto = false;
    while (v.size() != 1) {
        for (ull i = 1; i < v.size(); i++) {
            // cout << endl;
            // cout << "VECTOR:" << endl;
            // for (auto j : v)
            //     cout << j << endl;
            // cout << endl;
            // cout << &v[0] << " " << &v[i] << endl;
            //
            cout << "VECTOR SIZE: " << v.size() << endl;
            cout << "ITEM SIZES : ";
            for (auto j : v)
                cout << j.size() << " ";
            cout << endl;
            auto tmp1 = overlap(v[0], v[i]);
            auto tmp2 = overlap(v[i], v[0]);
            if (i == v.size() - 1 && tmp1.size() == 0 && tmp2.size() == 0) {
                used_goto = true;
                goto help;
            } else if (tmp1.size() == 0 && tmp2.size() == 0)
                continue;
            else if (tmp1.size() >= tmp2.size()) {
                v[0] = tmp1;
                v.erase(v.begin() + i);
                break;
            } else {
                v[0] = tmp2;
                v.erase(v.begin() + i);
                break;
            }
        }
    }
help:
    for (auto i : v)
        cout << i << endl;
    out << v[0] << endl;
    out.close();
    if (used_goto)
        cout << "DEU RUIM CAMBADA" << endl;
}
