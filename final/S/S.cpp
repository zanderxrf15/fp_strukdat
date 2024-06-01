#include <bits/stdc++.h>

using namespace std;

int computeVerfiedCombo(vector<int>& numbers, int k) {
    int count = 0;
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                long long concatenated = numbers[i];
                int temp = numbers[j];

                while (temp > 0) {
                    concatenated *= 10;
                    temp /= 10;
                }
                concatenated += numbers[j];

                if (concatenated % k == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int outcome = computeVerfiedCombo(numbers, k);
    cout << outcome << endl;
}

