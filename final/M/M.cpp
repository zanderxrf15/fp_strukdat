#include <bits/stdc++.h>

using namespace std;

bool isValidString(const string & s) {
    stack<char> pile;

    for (char strangle : s) {
        if ( strangle == '(' || strangle == '[' || strangle == '{') {
            pile.push(strangle);
        }
        else if ( strangle == ')' || strangle == ']' || strangle == '}') {
            if (pile.empty()) {
                return false;
            }

            char top = pile.top();
            pile.pop();

            if ((strangle == ')' && top != '(') || (strangle == ']' && top != '[') || (strangle == '}' && top != '{')) {
                return false;
            }
        }
    }
    return pile.empty();
}

int main() {
    string S;
    getline(cin, S);

    if (isValidString(S)) {
        cout << "valdi" << endl;
    }
    else {
      cout << "unvaldi" << endl;
    }
}
