#include <bits/stdc++.h>

using namespace std;

int BFS(vector<vector<int>>& proxRecord, int arrive);

int main() {
    int N;
    cin >> N;

    vector<vector<int>> proxRecord(N);

    int begin, compute;
    while (cin >> begin >> compute && (begin != -1 || compute != -1)) {
        proxRecord[begin].push_back(compute);
    }

    for (int a = 0; a < N; a++) {
        int move = BFS(proxRecord, a);
        if (move == -1) {
            cout << "gak bisa pulang mamah" << endl;
        }
         else {
            cout << move << endl;
        }
    }
}

int BFS(vector<vector<int>>& proxRecord, int begin) {
    vector<bool> tracking(proxRecord.size(), false);
    vector<int> move(proxRecord.size(), -1);

    queue<int> line;
    line.push(begin);
    tracking[begin] = true;
    move[begin] = 0;

    while (!line.empty()) {
        int burning = line.front();
        line.pop();

        for (int next : proxRecord[burning]) {
            if (!tracking[next]) {
                line.push(next);
                tracking[next] = true;
                move[next] = move[burning] + 1;
            }
            else if (next == begin) {
                return move[burning] + 1;
            }
        }
    }
    return -1;
}
