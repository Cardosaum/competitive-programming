#include <algorithm>
#include <bits/stdc++.h>
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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
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

int main() {
    SPEED;
    int n;
    int total = 1;
    ofstream output;

    cin >> n;
    vector<int> list_numbers(n);

    /* Inserting values into the array and calculating the total of permutations
     */
    for (int i = 0; i < n; i++) {
        list_numbers[i] = i + 1;
        total *= i + 1;
    }

    output.open("rosalind_sign.txt");
    total = total << n;

    output << total << endl;

    do {
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    output << "-";

                output << list_numbers[j] << " ";
            }

            output << endl;
        }
    } while (next_permutation(list_numbers.begin(), list_numbers.end()));

    output.close();
    return 0;
}
