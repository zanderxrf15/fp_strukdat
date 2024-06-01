#include <bits/stdc++.h>

using namespace std;

struct Node {
    int stats;
    Node* left;
    Node* right;

    Node(int worth) : stats(worth), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* root, int worth) {
        if (root == NULL) {
            return new Node(worth);
        }

        if (worth < root->stats) {
            root->left = insertNode(root->left, worth);
        }
        else if (worth > root->stats) {
            root->right = insertNode(root->right, worth);
        }

        return root;
    }

    Node* locateNode(Node* root, int worth) {
        if (root == NULL || root->stats == worth) {
            return root;
        }

        if (worth < root->stats) {
            return locateNode(root->left, worth);
        }
        else {
            return locateNode(root->right, worth);
        }
    }

    int obtainExtent(Node* root, int worth, int extension) {
        if (root == NULL) {
            return 0;
        }

        if (root->stats == worth) {
            return extension;
        }

        int leftExtent = obtainExtent(root->left, worth, extension + 1);
        if (leftExtent != 0) {
            return leftExtent;
        }

        int rightExtent = obtainExtent(root->right, worth, extension + 1);
        return rightExtent;
    }

    void obtainTraversal(Node* root, int& count, int kill, int& outcome) {
        if (root == NULL || count >= kill) {
            return;
        }

        obtainTraversal(root->left, count, kill, outcome);

        count++;
        if (count == kill) {
            outcome = root->stats;
            return;
        }

        obtainTraversal(root->right, count, kill, outcome);
    }

    string obtainTrack(Node* root, int worth) {
        if (root == NULL) {
            return "";
        }

        if (root->stats == worth) {
            return "S";
        }

        if (worth < root->stats) {
            string leftTrack = obtainTrack(root->left, worth);
            if (leftTrack != "") {
                return "L" + leftTrack;
            }
        }
        else {
            string rightTrack = obtainTrack(root->right, worth);
            if (rightTrack != "") {
                return "R" + rightTrack;
            }
        }
        return "";
    }

public:
    BST() : root(NULL) {}

    void insert(int worth) {
        root = insertNode(root, worth);
    }

    void find(int worth) {
        Node* node = locateNode(root, worth);
        if (node != NULL) {
            int extension = obtainExtent(root, worth, 1);
            cout << "on level " << extension << endl;
        }
        else {
            cout << "no " << worth << endl;
        }
    }

    void rank(int kill) {
        int count = 0;
        int output = -1;
        obtainTraversal(root, count, kill, output);
        cout << output << endl;
    }

    void track(int worth) {
        string track = obtainTrack(root, worth);
        if (track != "") {
            cout << track << endl;
        }
        else {
            cout << "no " << worth << endl;
        }
    }
};

int main() {
    BST tree;

    string cmd;
    int worth;

    while (cmd != "STOP") {
        cin >> cmd;
        if (cmd == "IN") {
            cin >> worth;
            tree.insert(worth);
        }
        else if (cmd == "FD") {
            cin >> worth;
            tree.find(worth);
        }
        else if (cmd == "RK") {
            cin >> worth;
            tree.rank(worth);
        }
        else if (cmd == "PH") {
            cin >> worth;
            tree.track(worth);
        }
    }
    cout << "done" << endl;
}
