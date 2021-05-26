#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    set<string> s_set;
    for (char c: s) {
        s_set.insert(string{c});
    }
    if (s_set.size()%2) {
        cout << "IGNORE HIM!\n";
    } else {
        cout << "CHAT WITH HER!\n";
    }
}
