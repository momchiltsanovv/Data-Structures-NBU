#include <iostream>

using namespace std;

int COUNT;
typedef struct node* po;

struct node {
    int data;
    po left;
    po right;
};

po root = NULL;

po findAndBuild(int turseno) {
    if (root == NULL) {
        cout << "Zakacham koren " << endl;
        root = new node;
        root->data = turseno;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else {
        po loc = root;
        po insert = NULL;
        while (loc != NULL && loc->data != turseno) {
            insert = loc;
            if (turseno > loc->data) {
                loc = loc->right;
            }
            else {
                loc = loc->left;
            }
        }
        if (loc == NULL) {
            cout << "Zakacham " << endl;
            loc = new node;
            loc->data = turseno;
            loc->left = NULL;
            loc->right = NULL;
            if (turseno < insert->data) {
                insert->left = loc;
            }
            else {
                insert->right = loc;
            }
        }
        else {
            cout << "Namerih " << turseno << endl;
        }
        return loc;
    }
}


void infixPrint(po root) {
    if (root != NULL) {
        infixPrint(root->left);
        cout << root->data << " ";
        infixPrint(root->right);
    }
    else {
        cout << " ";
    }
}


void print(po root, int space) {
    COUNT = 10;
    if (root == NULL)
        return;

    space += COUNT;
    print(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print(root->left, space);
}

void trii(po& root, int toDel) {
    po del = NULL;
    po loc = root;
    po tati = NULL;

    // Find the node to delete and its parent
    while (loc != NULL && loc->data != toDel) {
        tati = loc;
        if (toDel > loc->data) {
            loc = loc->right;
        }
        else {
            loc = loc->left;
        }
    }

    if (loc == NULL) {
        cout << "Nqma takuv element\n";
        return;
    }

    // Case 1: Node to be deleted is a leaf node
    if (loc->left == NULL && loc->right == NULL) {
        if (tati == NULL) {
            root = NULL;
        }
        else if (tati->left == loc) {
            tati->left = NULL;
        }
        else {
            tati->right = NULL;
        }
        delete loc;
    }
    // Case 2: Node to be deleted has one child
    else if (loc->left == NULL || loc->right == NULL) {
        po child = loc->left != NULL ? loc->left : loc->right;
        if (tati == NULL) {
            root = child;
        }
        else if (tati->left == loc) {
            tati->left = child;
        }
        else {
            tati->right = child;
        }
        delete loc;
    }
    // Case 3: Node to be deleted has two children
    else {
        po predParent = loc;
        po pred = loc->left;
        while (pred->right != NULL) {
            predParent = pred;
            pred = pred->right;
        }
        loc->data = pred->data;
        if (predParent->left == pred) {
            predParent->left = pred->left;
        }
        else {
            predParent->right = pred->left;
        }
        delete pred;
    }
}


int main() {
    char answer;
    int x;
    cout << "She tyrshish li? / Vmukvash li? (y/n): ";
    cin >> answer;
    while (answer != 'n') {
        cout << "Kakvo?: ";
        cin >> x;
        cout << endl;
        findAndBuild(x);
        cout << endl;
        cout << "She tyrshish li? / Vmukvash li? (y/n): ";
        cin >> answer;
    }


    cout << "Finalno durvo:\n";
    print(root, 5);

    cout << "\nInfix: ";
    infixPrint(root);
    cout << endl;

    cout << "She triish li?\n";
    cin >> answer;

    while (answer != 'n') {
        cout << "Kogo triesh?\n";
        cin >> x;
        trii(root, x);
        cout << "Eto durvoto:\n";
        print(root, 5);
        cout << "She triish li?\n";
        cin >> answer;
    }


    return 0;
}
