#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define endl '\n'
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
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

int main() {
    SPEED;

    int t;
    cin >> t;
    loop: while (t--) {
        // cout << "=" << t+1 << endl;
        int n;
        cin >> n;
        map<int,int> m;
        vi even;
        vi odd;
        vi mesh;
        while (n--) {
            int x;
            cin >> x;
            m[x]++;
            mesh.pb(x);
            if (x%2) {odd.pb(x);}
            else {even.pb(x);}
        }
        if (!(even.size()%2) && !(odd.size()%2)) {YES;goto loop;}
        // cout << "*" << t+1 << endl;
        for (auto i: mesh) {
            if (!(even.size()%2) && !(odd.size()%2)) {YES;goto loop;}
            if (m[i] && m[i-1]) {
                m[i]--;
                m[i-1]--;
                if (i%2) {
                    odd.erase(find(all(odd), i));
                    even.erase(find(all(even), i-1));
                } else {
                    even.erase(find(all(even), i));
                    odd.erase(find(all(odd), i-1));
                }
            } else if (m[i] && m[i+1]) {
                m[i]--;
                m[i+1]--;
                if (i%2) {
                    odd.erase(find(all(odd), i));
                    even.erase(find(all(even), i+1));
                } else {
                    even.erase(find(all(even), i));
                    odd.erase(find(all(odd), i+1));
                }
            }
        }
        // cout << "&" << t+1 << endl;
        NO;
    }
}
