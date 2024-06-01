#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Map {
    int destination;
    int death;
};

void addMap(vector<vector<Map>>& graph, int arrival, int destination, int death) {
    graph[arrival].push_back({destination, death});
}

int seekProtection(vector<vector<Map>>& graph, int n) {
    vector<int> deathHazards(n + 1, INF);
    deathHazards[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int villages = pq.top().second;
        int death = pq.top().first;
        pq.pop();

        if (death > deathHazards[villages]) {
            continue;
        }

        for (Map& edge : graph[villages]) {
            int nextVillages = edge.destination;
            int nextDeathhazard = max(death, edge.death);

            if (nextDeathhazard < deathHazards[nextVillages]) {
                deathHazards[nextVillages] = nextDeathhazard;
                pq.push({nextDeathhazard, nextVillages});
            }
        }
    }

    return deathHazards[n];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Map>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        addMap(graph, a, b, c);
        addMap(graph, b, a, c);
    }

    int outcome = seekProtection(graph, n);
    cout << outcome << endl;
}
