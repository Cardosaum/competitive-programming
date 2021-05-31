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

    int n;
    cin >> n;
    vector<ull> v;
    ull dano {0};
    rep(i,n) {
        int x;
        cin >> x;
        v.pb(x);
    }

    int i {0};
    while (!v.empty()) {
        ++i;
        cout << i << endl;
        printf("front: %llu\tback: %llu\n", v.front(), v.back());
        printf("before dano: %llu\n", dano);
        if ((int)v.size() == 1) {
            cout << "last" << endl;
            dano += v.front();
            v.clear();
        }
        else {
            dano += v.front() + v.back();
            if (v.front() > v.back()) {
                cout << "remove front" << endl;
                v.erase(v.begin());
            } else {
                cout << "remove back" << endl;
                v.pop_back();
                // continue;
            }
        }
        printf("after dano: %llu\n", dano);
    }
    cout << dano << endl;
}
