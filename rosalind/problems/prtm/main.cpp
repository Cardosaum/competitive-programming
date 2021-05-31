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
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;
typedef istringstream iss;
typedef set<int> si;
typedef map<int,int> mii;

typedef set<int>::iterator si_it;
typedef map<int,int>::iterator mii_it;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

[[maybe_unused]] const int INF = 1e9 + 7;
[[maybe_unused]] const int MOD = 1e9 + 7;
[[maybe_unused]] const int MAXN = 1e6 + 3;

int main() {
    SPEED;

    map<char,ld> aa {
    {'A',71.03711},
    {'C',103.00919},
    {'D',115.02694},
    {'E',129.04259},
    {'F',147.06841},
    {'G',57.02146},
    {'H',137.05891},
    {'I',113.08406},
    {'K',128.09496},
    {'L',113.08406},
    {'M',131.04049},
    {'N',114.04293},
    {'P',97.05276},
    {'Q',128.05858},
    {'R',156.10111},
    {'S',87.03203},
    {'T',101.04768},
    {'V',99.06841},
    {'W',186.07931},
    {'Y',163.06333}
};

    string s;
    getline(cin, s);
    ld x {0};

    for (auto const& i: s) {x += aa[i];}
    cout << fixed;
    cout << x << endl;

}
