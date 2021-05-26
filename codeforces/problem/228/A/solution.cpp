#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    istringstream ss(s);
    int n;
    vector<unsigned> shoes;

    while (ss >> n) {
        if (find(shoes.begin(), shoes.end(), n) == shoes.end()) {
            shoes.emplace_back(n);
        }
    }
    cout << 4 - shoes.size();
}
