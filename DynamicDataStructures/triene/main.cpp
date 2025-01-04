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

void trii(int toDel) {
    po loc = root;
    po tati = NULL;
    po pomosht = NULL;
    po del = NULL;

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

    if (loc->left == NULL && loc->right == NULL) {
        del = loc;

        if (tati != NULL) {
            if (tati->left == loc)
                tati->left = NULL;
            else
                tati->right = NULL;
        }
        else {
            root = NULL;
        }
        delete del;
    }

    else if (loc->left == NULL || loc->right == NULL) {
        po child = (loc->left != NULL) ? loc->left : loc->right;

        if (tati != NULL) {
            if (tati->left == loc)
                tati->left = child;
            else
                tati->right = child;
        }
        else {
            root = child;
        }

        delete loc;
    }

    else {
        pomosht = loc->left;
        po parentOfPomosht = loc;

        while (pomosht->right != NULL) {
            parentOfPomosht = pomosht;
            pomosht = pomosht->right;
        }

        loc->data = pomosht->data;

        if (parentOfPomosht->right == pomosht)
            parentOfPomosht->right = pomosht->left;
        else
            parentOfPomosht->left = pomosht->left;

        delete pomosht;
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
        trii(x);
        cout << "Eto durvoto:\n";
        print(root, 5);
        cout << "She triish li?\n";
        cin >> answer;
    }

    return 0;
}
