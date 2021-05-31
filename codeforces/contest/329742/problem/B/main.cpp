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
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;
typedef istringstream iss;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

[[maybe_unused]] const int INF = 1e9 + 7;
[[maybe_unused]] const int MOD = 1e9 + 7;
[[maybe_unused]] const int MAXN = 1e6 + 3;

int main() {
    SPEED;

    map<int,vector<int>> recp;
    map<int,vector<int>> ingt;

    int n,m;
    cin >> n;
    cin >> m;

    rep(i,n) {
        int a,b,c;
        cin >> a;
        cin >> b;
        cin >> c;
        vi v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        recp[i] = v;
    }

    rep(i,m) {
        int a,b,c;
        cin >> a;
        cin >> b;
        cin >> c;
        vi v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        ingt[i] = v;
    }

    // int receita {0};
    // int ingrediente {0};
    int bolos {0};
    rep(i,n) {
        rep(j,m) {
            int a,b,c;
            int bolos_possiveis {0};
            a = ingt[j][0] / recp[i][0];
            b = ingt[j][1] / recp[i][1];
            c = ingt[j][2] / recp[i][2];
            bolos_possiveis = min({a,b,c});
            // if (bolos_possiveis > bolos) {bolos = bolos_possiveis; receita = i; ingrediente = j;}
            if (bolos_possiveis > bolos) {bolos = bolos_possiveis;}
            // cout << i << ';' << j << "\t" << bolos_possiveis << endl;
        }
    }
    cout << bolos << endl;
}
