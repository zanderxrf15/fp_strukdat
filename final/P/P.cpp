#include <bits/stdc++.h>

using namespace std;

struct Map {
    int report = 0;
    int explored= 0;
};

Map plexus[105][105];
int currentPos = 0;

bool performFloodFill(int x, int y)
{
    plexus[x][y].explored = currentPos;

    if (plexus[x+1][y].report == 2 || plexus[x][y+1].report == 2 || plexus[x-1][y].report == 2 || plexus[x][y-1].report == 2)
    {
        plexus[x][y].report = 2;
        return true;
    }

    if (plexus[x+1][y].report == 1 && currentPos != plexus[x+1][y].explored)
        if (performFloodFill(x+1, y))
            return true;

    if (plexus[x][y+1].report == 1 && currentPos != plexus[x][y+1].explored)
        if (performFloodFill(x, y+1))
            return true;

    if (plexus[x-1][y].report == 1 && currentPos != plexus[x-1][y].explored)
        if (performFloodFill(x-1, y))
            return true;

    if (plexus[x][y-1].report == 1 && currentPos != plexus[x][y-1].explored)
        if (performFloodFill(x, y-1))
            return true;

    return false;
}

int main()
{
    int rows, columns;
    vector<pair<int, int>> ignitePoint;

    cin >> rows >> columns;

    char inputCmd, plexStats[rows+1][columns+1];

    for (int r = 1; r <= rows; r++)
    {
        for (int c = 1; c <= columns; c++)
        {
            cin >> inputCmd;
            plexStats[r][c] = inputCmd;

            if (inputCmd == 'X')
                continue;

            plexus[r][c].report = 1;

            if (inputCmd == 'O' && r > 1 && c > 1 && r < rows && c < columns)
                ignitePoint.push_back(make_pair(r, c));

            if (inputCmd == '^' || r == 1 || c == 1 || r == rows || c == columns)
                plexus[r][c].report = 2;
        }
    }

    int ignitePointNumero = ignitePoint.size();

    for (int i = 0; i < ignitePointNumero; i++)
    {
        currentPos++;
        if (!performFloodFill(ignitePoint[i].first, ignitePoint[i].second))
            plexStats[ignitePoint[i].first][ignitePoint[i].second] = 'X';
    }

    for (int r = 1; r <= rows; r++)
    {
        for (int c = 1; c <= columns; c++)
            cout << plexStats[r][c];

        cout << endl;
    }
}

