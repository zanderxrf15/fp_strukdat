#include <bits/stdc++.h>

using namespace std;

void igniteTeumeMap(int N, int M, vector<pair<int, int>>& teume) {
    vector<vector<int>> map(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
       int x = teume[i].first;
       int y = teume[i].second;

       map[y - 1][x - 1] = 1;

        for (int j = 0; j < 4; j++) {
            if (y - 3 + j >= 1 && y - 3 + j <= N && x + j >= 1 && x + j <= N && map[y - 3 + j - 1][x + j - 1] == 0)
                map[y - 3 + j - 1][x + j - 1] = 4;
            if (y - 3 + j >= 1 && y - 3 + j <= N && x - j >= 1 && x - j <= N && map[y - 3 + j - 1][x - j - 1] == 0)
                map[y - 3 + j - 1][x - j - 1] = 4;
            if (y + 3 - j >= 1 && y + 3 - j <= N && x + j >= 1 && x + j <= N && map[y + 3 - j - 1][x + j - 1] == 0)
                map[y + 3 - j - 1][x + j - 1] = 4;
            if (y + 3 - j >= 1 && y + 3 - j <= N && x - j >= 1 && x - j <= N && map[y + 3 - j - 1][x - j - 1] == 0)
                map[y + 3 - j - 1][x - j - 1] = 4;
        }

        for (int j = 0; j < 3; j++) {
            if (y - 2 + j >= 1 && y - 2 + j <= N && x + j >= 1 && x + j <= N && (map[y - 2 + j - 1][x + j - 1] == 0 || map[y - 2 + j - 1][x + j - 1] == 4))
                map[y - 2 + j - 1][x + j - 1] = 3;
            if (y - 2 + j >= 1 && y - 2 + j <= N && x - j >= 1 && x - j <= N && (map[y - 2 + j - 1][x - j - 1] == 0 || map[y - 2 + j - 1][x - j - 1] == 4))
                map[y - 2 + j - 1][x - j - 1] = 3;
            if (y + 2 - j >= 1 && y + 2 - j <= N && x + j >= 1 && x + j <= N && (map[y + 2 - j - 1][x + j - 1] == 0 || map[y + 2 - j - 1][x + j - 1] == 4))
                map[y + 2 - j - 1][x + j - 1] = 3;
            if (y + 2 - j >= 1 && y + 2 - j <= N && x - j >= 1 && x - j <= N && (map[y + 2 - j - 1][x - j - 1] == 0 || map[y + 2 - j - 1][x - j - 1] == 4))
                map[y + 2 - j - 1][x - j - 1] = 3;
        }

        if (x + 1 >= 1 && x + 1 <= N && (map[y - 1][x] == 0 || map[y - 1][x] == 4 || map[y - 1][x] == 3))
            map[y - 1][x] = 2;
        if (x - 1 >= 1 && x - 1 <= N && (map[y - 1][x - 2] == 0 || map[y - 1][x - 2] == 4 || map[y - 1][x - 2] == 3))
            map[y - 1][x - 2] = 2;
        if (y + 1 >= 1 && y + 1 <= N && (map[y][x - 1] == 0 || map[y][x - 1] == 4 || map[y][x - 1] == 3))
            map[y][x - 1] = 2;
        if (y - 1 >= 1 && y - 1 <= N && (map[y - 2][x - 1] == 0 || map[y - 2][x - 1] == 4 || map[y - 2][x - 1] == 3))
            map[y - 2][x - 1] = 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> teume(M);
    for (int i = 0; i < M; i++) {
        cin >> teume[i].first >> teume[i].second;
    }

    igniteTeumeMap(N, M, teume);
}
