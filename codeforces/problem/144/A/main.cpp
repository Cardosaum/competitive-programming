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

    int moves {0};

    int n;
    cin >> n;

    int max {0};
    int argmax {0};
    int min {0};
    int argmin {0};

    rep(i,n) {
        int x;
        cin >> x;
        // cout << x << " ";
        if (!i) {max = x; min = x; argmax = i; argmin = i; continue;}
        if (x > max) {max = x; argmax = i; continue;}
        if (x <= min) {min = x; argmin = i; continue;}
    }
    // cout << endl;

    // cout << "max: " << max << "\targmax: " << argmax << endl;
    // cout << "min: " << min << "\targmin: " << argmin << endl;
    // cout << endl;

    while (argmax != 0 || argmin != n-1) {
        // cout << "argmax: " << argmax << "\t";
        // cout << "argmin: " << argmin << endl;
        ++moves;
        if (argmax-1 == argmin) {--argmax;++argmin;}
        else if (argmax) {--argmax;}
        else {++argmin;}
    }

    cout << moves << endl;
}
