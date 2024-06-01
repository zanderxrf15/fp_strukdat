#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> maps;
vector<bool> visited;
vector<int> parent;

bool bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == target) {
            return true;
        }

        for (int border : maps[node]) {
            if (!visited[border]) {
                q.push(border);
                visited[border] = true;
                parent[border] = node;
            }
        }
    }

    return false;
}

vector<int> detectTrack(int arrival, int kill) {
    vector<int> track;
    int curr = kill;
    while (curr != -1) {
        track.push_back(curr);
        curr = parent[curr];
    }
    reverse(track.begin(), track.end());
    return track;
}

int main() {
    int N, E;
    cin >> N >> E;

    maps.resize(N + 1);
    visited.assign(N + 1, false);
    parent.resize(N + 1);

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        maps[A].push_back(B);
        maps[B].push_back(A);
    }

    if (bfs(1, N)) {
        vector<int> track = detectTrack(1, N);
        cout << track.size() << endl;
        for (int node : track) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "RIP LAPET 2023" << endl;
    }
}
