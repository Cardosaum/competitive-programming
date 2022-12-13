#include <bits/stdc++.h>
#include <thread>
#include <mutex>

using namespace std;

mutex m;

void binary_search(const vector<int>& arr, int x) {
    auto it = lower_bound(arr.begin(), arr.end(), x);
    if (it == arr.end() || *it != x) {
        m.lock();
        cout << "-1" << endl;
        m.unlock();
    } else {
        m.lock();
        cout << it - arr.begin() << endl;
        m.unlock();
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<thread> threads;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        threads.push_back(thread(&binary_search, ref(arr), x));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
