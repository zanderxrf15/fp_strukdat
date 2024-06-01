#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> stacks;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (stacks.empty()) {
            if (x == 1) {
                stacks.push(1);
            }
            stacks.push(0);
        }
        else if (stacks.size() == 1) {
            if (stacks.top() == 0) {
                if (x == 0) {
                    stacks.pop();
                }
            }
            else {
                if (x == 1) {
                    stacks.pop();
                }
                else {
                    stacks.push(0);
                }
            }
        }
        else if (stacks.top() == 0) {
            stacks.pop();
            if (x == 1) {
                stacks.push(1);
                stacks.push(0);
                stacks.push(1);
                stacks.push(0);
            }
        }
        else {
            if (x == 0) {
                stacks.push(0);
            }
            else {
                stacks.pop();
            }
        }
    }

    cout << static_cast<int>(stacks.size()) << endl;
}




