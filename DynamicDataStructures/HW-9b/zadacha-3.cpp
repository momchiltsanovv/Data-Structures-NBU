#include <iostream>

using namespace std;

struct vuzel {
    char data;
    vuzel* left;
    vuzel* right;
};

vuzel* ibd(const int& size) {
    int liqvaChast = size / 2;
    int dqsnqChast = size - liqvaChast - 1;
    vuzel* novo = new vuzel;
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
void infiksno(vuzel* root) {
    if (root == NULL)
        return;
    infiksno(root->left);
    cout << root->data << " ";
    infiksno(root->right);
}
void printExpression(vuzel* root) {
    if (root == NULL) return;


    if (root->left != NULL || root->right != NULL) {
        cout << "(";
    }
    printExpression(root->left);
    cout << root->data;
    printExpression(root->right);

    if (root->left != NULL || root->right != NULL) {
        cout << ")";
    }
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
int main () {
    int size;
    cin >> size;
    vuzel* root = ibd(size);
    print(root, 10);

    cout << endl;
    infiksno(root);
    cout << endl;
    printExpression(root);


    free(root);
}