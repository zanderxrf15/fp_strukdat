#include <bits/stdc++.h>

using namespace std;

vector<int> addRecords(vector<int>& record1, vector<int>& record2) {
    int M = record1.size();
    int N = record2.size();

    if (M < N) {
        swap(record1, record2);
        swap(M, N);
    }

    vector<int> output;

    int dispatch = 0;

    int i = M - 1;
    int j = N - 1;

    while (i >= 0) {
        int amount = record1[i] + dispatch;

        if (j >= 0) {
            amount += record2[j];
            j--;
        }

        output.push_back(amount % 10);
        dispatch = amount / 10;

        i--;
    }

    if (dispatch > 0) {
        output.push_back(dispatch);
    }

    reverse(output.begin(), output.end());

    return output;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> record1(M);
    vector<int> record2(N);

    for (int i = 0; i < M; i++) {
        cin >> record1[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> record2[i];
    }

    vector<int> amount = addRecords(record1, record2);

    for (int cipher : amount) {
        cout << cipher;
    }
    cout << endl;
}
