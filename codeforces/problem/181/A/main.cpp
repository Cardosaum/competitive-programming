#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n {0};
    int x {0};
    int y {0};
    vector<pair<int,int>> xy;
    while (getline(cin, s)) {
        for (auto i = 0; i < (int)s.size(); i++) {
            if (s[i] == '*') {
                xy.push_back(make_pair(n,1+i));
            }
        }
        ++n;
    }
    map<string,int> dictx;
    map<string,int> dicty;
    for (auto i = 0; i < (int)xy.size(); i++) {
        // printf("N: %i\tI: %i\n", xy[i].first, xy[i].second);

        string a {to_string(xy[i].first)};

        auto ok = dictx.try_emplace(a, 1);
        if (!ok.second) {
            dictx[a] += 1;
        }

        a  = to_string(xy[i].second);
        ok = dicty.try_emplace(a, 1);
        if (!ok.second) {
            dicty[a] += 1;
        }
    }
    for (auto const& [key, val] : dictx) {
        // cout << key << ": " << val << endl;
        if (val == 1) {
            x = stoi(key);
            // printf("X is: %i\n", x);
            break;
        }
    }
    for (auto const& [key, val] : dicty) {
        // cout << key << ": " << val << endl;
        if (val == 1) {
            y = stoi(key);
            // printf("Y is: %i\n", y);
            break;
        }
    }
    cout << x << " " << y << endl;
}
