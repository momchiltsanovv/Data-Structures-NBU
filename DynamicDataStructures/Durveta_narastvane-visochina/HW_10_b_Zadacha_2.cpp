#include <iostream>
using namespace std;
int COUNT;

typedef struct node* po;

struct node {
    int data;
    po left;
    po right;
};

po ibd(int n) {
    int nl = n / 2;
    int nd = n - nl - 1;
    po p = new node;
    if (n != 0) {
        p->left = ibd(nl);
        cin >> p->data;
        p->right = ibd(nd);
    }
    else {
        p = NULL;
    }
    return p;
}
po find(int turseno) {
    po loc = root;
    int checks = 0;

    while (loc != NULL) {
        checks++;
        cout << "Проверка: " << loc->data << endl;
        if (turseno == loc->data) {
            cout << "Намерих: " << turseno << " (проверки: " << checks << ")" << endl;
            return loc;
        }
        if (turseno < loc->data) {
            loc = loc->left;
            cout << "Слизам наляво." << endl;
        } else {
            loc = loc->right;
            cout << "Слизам надясно." << endl;
        }
    }
    cout << "Не намерих: " << turseno << " (проверки: " << checks << ")" << endl;
    return NULL;
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
    int n;
    po root;
    cin >> n; //broi vuzli
    root = ibd(n);
    print(root, 5);

    free(root);
    return 0;
}
