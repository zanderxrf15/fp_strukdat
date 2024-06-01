#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> costs;
        int maximumReckoning = 0;

        for (int i = 0; i < n; i++) {
            int term;
            cin >> term;
            costs[term]++;
            maximumReckoning = max(maximumReckoning, costs[term]);
        }

        if (costs.size() == 1) {
            cout << n << endl;
        }
        else if (costs.size() == 2) {
            cout << abs(costs.begin()->second - (--costs.end())->second) << endl;
        }
        else {
            cout << max(2 * maximumReckoning - n, n % 2) << endl;
        }
    }
}

