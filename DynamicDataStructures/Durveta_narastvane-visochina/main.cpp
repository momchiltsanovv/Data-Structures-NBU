//
// Created by Momchil Tsanov on 14.12.24.
//
//
// Created by Momchil Tsanov on 11.12.24.
//
#include <iostream>
using namespace std;


struct vuzel {
    int data;
    vuzel* left;
    vuzel* right;
};

vuzel* ibd(const int& size) {
    int liqvaChast = size / 2;
    int dqsnqChast = size - liqvaChast - 1;
    vuzel* novo = new vuzel;
    if (size != 0) {
        novo->left = ibd(liqvaChast);
        cin >> novo->data;
        novo->right = ibd(dqsnqChast);
    }
    else {
        novo = NULL;
    }

    return novo;
}


vuzel* find(vuzel* koren, int turseno) { // lokaciq
    vuzel* loc = koren;

    while (loc != NULL && loc->data != turseno) {
        cout <<" vuzel: " << loc->data <<endl;
        if (turseno > loc->data) { // slizame nadolu
            loc = loc->right;
            cout << "slqzoh nqdqsno" << endl;
        }
        else {
            loc = loc->left;
            cout << "sldqzoh nalqvo" << endl;
        }
    }
    if (loc == NULL) {
        cout << "nqma go" << endl;
    }
    else {
        cout << "namerih" << endl;
    }

    return loc;
}


void print(const vuzel* root, int space) {
    int count = 10;
    if (root == NULL)
        return;

    space += count;
    print(root->right, space);
    cout << endl;

    for (int i = count; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print(root->left, space);
}


void infiksno(vuzel* root) {
    if (root == NULL)
        return;
    infiksno(root->left);
    cout << root->data << " ";
    infiksno(root->right);
}

void prefiksno(vuzel* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    prefiksno(root->left);
    prefiksno(root->right);
}

void postfiksno(vuzel* root) {
    if (root == NULL)
        return;
    postfiksno(root->left);
    postfiksno(root->right);
    cout << root->data << " ";
}


int main() {
    int size;
    cin >> size;
    vuzel* root = ibd(size);
    print(root, 5);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << " инфиксно " << endl;
    infiksno(root);
    cout << endl;
    cout << endl;
    cout << " префиксно " << endl;
    prefiksno(root);
    cout << endl;
    cout << endl;
    cout << " постфиксно " << endl;
    postfiksno(root);

    cout << endl;

    cout << "kvo tursish: ";
    int x;
    cin >> x;

    vuzel* result = find(root, x);
    cout << result << endl;

    free(root);
    return 0;
}
