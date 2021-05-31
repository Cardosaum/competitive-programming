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

    int a,b,c,d;
    // int ta {0};
    // int tb {0};
    // int tc {0};
    // int td {0};
    int win {0};
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    rep(i,a) {
        rep(j,c){
            // printf("i: %i\tj: %i\tb: %i\td: %i\twin: %i\n", i,j,b,d,win);
            if (i+b > j+d) {win++;}
        }
    }
    cout << (ld)((ld)win/(ld)(a*c)) << endl;
}
