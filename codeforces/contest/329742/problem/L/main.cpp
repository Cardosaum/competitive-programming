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

ld rectangle(ull x1,ull y1,ull x2,ull y2) {
    ull x = min({x1,x2});
    ull y = min({y1,y2});
    ull y0 = 0;
    ull x0 = max({x1,x2});
    return (ld)((x0-x) * (y-y0));
}

ld triangle(ull x1,ull y1,ull x2,ull y2) {
    ull x0,y0;
    if (y1 > y2) {
        y0 = y2;
        x0 = x1;
    } else if (y1 < y2) {
        y0 = y1;
        x0 = x2;
    } else {
        return 0;
    }
    return fabs( (ld)llabs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1))/(ld)2 );
}

int main() {
    SPEED;

    ld area {0};
    ull x1;
    ull y1;
    ull x2;
    ull y2;
    ull points;
    cin >> points;

    rep(i,points) {
        if (!i) {cin >> x1; cin >> y1; x2 = x1; y2 = y1; continue;}
        x1 = x2;
        y1 = y2;
        cin >> x2;
        cin >> y2;

        area += triangle(x1,y1,x2,y2);
        area += rectangle(x1,y1,x2,y2);
    }

    cout << fixed;
    cout << area << endl;
    // cout << triangle_area(x1,y1,x2,y2) << endl;
    // cout << rectangle_area(x1,y1,x2,y2) << endl;
}
