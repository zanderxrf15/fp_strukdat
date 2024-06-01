 #include <bits/stdc++.h>

using namespace std;

struct Node {
    int worth;
    Node* host;
    Node* left;
    Node* right;
};

struct BST {
    Node* root;
    unsigned int size;
};

Node* createNode(int code) {
    Node* newNode = new Node;
    newNode->worth = code;
    newNode->host = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int code) {
    if (root == nullptr)
        return createNode(code);

    if (code < root->worth) {
        root->left = insert(root->left, code);
        root->left->host = root;
    }
    else if (code > root->worth) {
        root->right = insert(root->right, code);
        root->right->host = root;
    }
    return root;
}

void traverse(Node* root, int numero, bool& encounter) {
    if (!encounter && root && (root->left || root->right)) {
        if (root->left && root->right) {
            if (numero == (root->worth + root->left->worth + root->right->worth) ||
                (root->host && numero == (root->worth + root->host->worth + root->right->worth)) ||
                (root->host && numero == (root->worth + root->left->worth + root->host->worth)))
                encounter = true;
            else {
                traverse(root->left, numero, encounter);
                traverse(root->right, numero, encounter);
            }
        }
        else if (root->left) {
            if (root->host && numero == (root->worth + root->host->worth + root->left->worth))
                encounter = true;
            else {
                traverse(root->left, numero, encounter);
                traverse(root->right, numero, encounter);
            }
        }
        else if (root->right) {
            if (root->host && numero == (root->worth + root->host->worth + root->right->worth))
                encounter = true;
            else {
                traverse(root->left, numero, encounter);
                traverse(root->right, numero, encounter);
            }
        }
    }
}

void fire(BST* tree) {
    tree->root = nullptr;
    tree->size = 0u;
}

bool isEmpty(BST* tree) {
    return tree->root == nullptr;
}

void insert(BST* tree, int code) {
    tree->root = insert(tree->root, code);
    tree->size++;
}

void traverse(BST* tree, int numero, bool& encounter) {
    encounter = false;
    if (tree->root)
        traverse(tree->root, numero, encounter);
}

int main() {
    BST nuclear;
    fire(&nuclear);
    int a, generation;
    cin >> a;
    for (int k = 0; k < a; k++) {
        cin >> generation;
        insert(&nuclear, generation);
    }

    int reckon;
    cin >> reckon;
    bool encounter;
    traverse(&nuclear, reckon, encounter);
    if (encounter)
        cout << reckon << " Selamat! Kalian menemukan harta karunnya" << endl;
    else
        cout << reckon << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;
}
