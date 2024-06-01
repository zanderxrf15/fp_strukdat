#include <iostream>
#define MOD 1000000009

using namespace std;

long long pow(long long base, long long exp) {
    long long output = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            output = (output * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return output;
}

int main() {
    int m;
    cin >> m;

    while (m--) {
        int n;
        cin >> n;

        long long x = n - 1;
        long long output = pow(2, (x * (x + 1)) / 2);
        cout << "Zodiak found: " << output << " signs" << endl;
    }
}
