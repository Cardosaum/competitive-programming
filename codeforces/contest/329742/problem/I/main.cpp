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

int contaminados(int n, int k) {
    if (n <= 2) {return 1;}
    int a {1};
    int b {1};
    int c {0};
    rep(i, n-2) {
        int tmp_a = (a % 2) ? a / 2 + 1 : a / 2;
        int tmp_b = (b % 2) ? b / 2 + 1 : b / 2;
        // printf("a; %i\tb: %i\tc: %i\ttmp_a: %i\ttmp_b: %i\n",a,b,c,tmp_a,tmp_b);
        c = k * ((tmp_a)+(tmp_b));
        // printf("C: %i\n",c);
        a = b;
        b = c;
    }
    return b;
}
// ld k4(int i) {return contaminados(i, 4);}

int main() {
    SPEED;
    int n;
    cin >> n;
    // cout << contaminados(n,3) << endl;
    // cout << contaminados(n,4) << endl;
    cout << contaminados(n,4) - contaminados(n,3) << endl;
}
