#include <bits/stdc++.h>

using namespace std;

struct Node {
    int reinforce;
    Node* left;
    Node* right;
    Node(int force) : reinforce(force), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int reinforce) {
    if (node == NULL) {
        return new Node(reinforce);
    }
    if (reinforce < node -> reinforce) {
        node -> left = insert(node -> left, reinforce);
    }
    else if (reinforce > node -> reinforce) {
        node -> right = insert(node -> right, reinforce);
    }
    return node;
}

void seekReinforcement(Node* root);

int main() {
    Node* root = NULL;

    int N;
    while (cin >> N) {
        root = insert(root, N);
    }

    seekReinforcement(root);
    cout << endl;
}

void seekReinforcement(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int seriesReinforced = q.size();
        int maximumForce = INT_MIN;

        for (int y = 0; y < seriesReinforced; y++) {
            Node* current = q.front();
            q.pop();

            maximumForce = max(maximumForce, current -> reinforce);

            if (current -> left) {
                q.push(current -> left);
            }
            if (current -> right) {
                q.push(current -> right);
            }
        }
        cout << maximumForce << " ";
    }
}

