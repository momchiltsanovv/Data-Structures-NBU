//
// Created by Momchil Tsanov on 18.12.24.
//

#include <iostream>
using namespace std;

struct vuzel {
    int data;
    vuzel* left;
    vuzel* right;
};

vuzel* ibd(int* values, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    vuzel* novo = new vuzel;
    novo->data = values[mid];
    novo->left = ibd(values, start, mid - 1);
    novo->right = ibd(values, mid + 1, end);
    return novo;
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

//113172
int main() {
    int l = 11;
    int m = 72;


    int values[l + m];
    for (int i = 0; i < l; i++) {
        values[i] = i + 1;
    }
    for (int i = l; i < l + m; i++) {
        values[i] = i - l + 1;
    }

    vuzel* root = ibd(values, 0, l + m - 1);


    print(root, 5);
    cout << endl;
    cout << endl;
    cout << " инфиксно " << endl;
    infiksno(root);
    cout << endl;
    cout << " префиксно " << endl;
    prefiksno(root);
    cout << endl;
    cout << " постфиксно " << endl;
    postfiksno(root);
    cout << endl;


    free(root);

    return 0;

}

