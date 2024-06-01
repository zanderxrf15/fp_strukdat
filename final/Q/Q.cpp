#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> proxRecord(1000);

void dijkstra(vector<int>& outcome, int ignite, int summitCompute) {
    vector<bool> visited(summitCompute, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    outcome = vector<int>(summitCompute, INT_MAX);

    pq.push(make_pair(0, ignite));
    outcome[ignite] = 0;

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();

        if (visited[temp.second])
            continue;

        visited[temp.second] = true;

        for (auto summit : proxRecord[temp.second]) {
            int nextSummit = summit.first;
            int weight = summit.second;

            if (temp.first + weight < outcome[nextSummit]) {
                outcome[nextSummit] = temp.first + weight;
                pq.push(make_pair(outcome[nextSummit], nextSummit));
            }
        }
    }
}

int main() {
    int v;
    cin >> v;
    string resto;
    int cost;
    map<int, string> cost_resto;
    map<int, int> cost_guide;

    for (int i = 1; i <= v; i++) {
        cin >> resto >> cost;
        cost_resto[cost] = resto;
        cost_guide[i] = cost;
    }

    int e;
    cin >> e;
    int v1, v2, w;

    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> w;
        proxRecord[v1].push_back({v2, w});
        proxRecord[v2].push_back({v1, w});
    }

    int d;
    cin >> d;
    vector<int> outcome;
    dijkstra(outcome, 0, v + 5);
    int minimalCost = INT_MAX;
    string cheapFood;

    for (int i = 1; i <= v; i++) {
        if (cost_guide[i] < minimalCost && outcome[i] <= d) {
            minimalCost = cost_guide[i];
            cheapFood = cost_resto[minimalCost];
        }
    }
    cout << "hari ini makan di " << cheapFood << endl;
}


