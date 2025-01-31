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

po ibd(int n) {
    int nl = n / 2;
    int nd = n - nl - 1;
    po p = new node;
    if (n != 0) {
        cin >> p->data;
        p->left = ibd(nl);
        p->right = ibd(nd);
    }
    else {
        p = NULL;
    }
    return p;
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


int main() {
    int size;
    po root;
    cout << "Въведи размер: ";
    cin >> size;
    root = ibd(size);
    print(root, 5);

    free(root);
    return 0;
}
