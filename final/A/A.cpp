#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, map<string, vector<string>>> email;
    map<string, string> participant;
    int N, Q;
    string internetProtocol, tag, uploadIP, acquireIP, tweet;

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> internetProtocol >> tag;
        participant[internetProtocol] = tag;
    }

    cin.ignore();

    for (int j = 0; j < Q; j++) {
        cin >> uploadIP >> acquireIP;
        cin.ignore();
        getline(cin, tweet);

        if (participant.count(uploadIP) == 0 || participant.count(acquireIP) == 0) {
            continue;
        }

        email[acquireIP][uploadIP].push_back(tweet);
    }

    for (const auto& twt : email) {
        const auto& tag = twt.first;
        const auto& convo = twt.second;

        cout << "===========" << endl;
        cout << "Mail: " << participant[tag] << endl;

        for (const auto& twt : convo) {
            const auto& from = twt.first;
            cout << "From: " << participant[from] << endl;
            const auto& txt = twt.second;

            for (const auto& direction : txt) {
                cout << ">> " << direction << endl;
            }
        }
    }
}
