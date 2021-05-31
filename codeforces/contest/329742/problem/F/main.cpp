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

void print_naves(vector<ii> const& naves) {
    for (auto const& i: naves) {
        printf("(%i,%i)", i.first, i.second);
    }
    cout << endl;
}

void delete_nave(int x, int y, vector<ii>& naves) {
    for (int i = 0; i < (int)naves.size(); i++) {
        if (naves[i].first == x && naves[i].second == y) {naves.erase(naves.begin()+i);break;}
    }
}

int main() {
    // SPEED;

    int n,m,q;
    cin >> n;
    cin >> m;
    cin >> q;

    vector<ii> naves;
    vector<ii> bombas;

    rep(i,m) {
        int x,y;
        cin >> x;
        cin >> y;
        naves.pb(mp(x,y));
    }
    int original = (int)naves.size();
    // print_naves(naves);
    rep(j,q) {
        int x,y;
        cin >> x;
        cin >> y;
        // printf("=(%i,%i)=\n", x,y);
        // print_naves(naves);

        rep(u,5) {
            switch (u) {
                case 0: delete_nave(x,y,naves);break;
                case 1: delete_nave(x+1,y,naves);break;
                case 2: delete_nave(x-1,y,naves);break;
                case 3: delete_nave(x,y+1,naves);break;
                case 4: delete_nave(x,y-1,naves);break;
            }

        }
    }
    cout << original - naves.size() << endl;
}
