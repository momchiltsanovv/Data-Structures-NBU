//
// Created by Momchil Tsanov on 11.12.24.
//
#include <iostream>
using namespace std;


struct durvo {
    char data;
    durvo* left;
    durvo* right;
};

durvo* ibd(int& size) {
    int liqvaChast = size / 2;
    int dqsnqChast = size - liqvaChast - 1;
    durvo* novo = new durvo;
    if (size != 0) {
        cin >> novo->data;
        novo->left = ibd(liqvaChast);
        novo->right = ibd(dqsnqChast);
    }
    else {
        novo = NULL;
    }

    return novo;
}

void print(durvo* root, int space) {
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


void infiksno(durvo* root) {
    if (root == NULL)
        return;
    infiksno(root->left);
    cout << root->data << " ";
    infiksno(root->right);
}
void prefiksno(durvo* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    prefiksno(root->left);
    prefiksno(root->right);
}

void postfiksno(durvo* root) {
    if (root == NULL)
        return;
    postfiksno(root->left);
    postfiksno(root->right);
    cout << root->data << " ";
}



int main() {
    int size;
    cin >> size;
    durvo* root = ibd(size);
    print(root, 5);
    cout << endl;
    cout << endl;
    cout << endl;
    infiksno(root);
    cout << endl;
    cout << endl;
    prefiksno(root);
    cout << endl;
    cout << endl;
    postfiksno(root);
    free(root);
    return 0;
    
}
