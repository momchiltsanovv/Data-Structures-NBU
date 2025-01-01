//
// Created by Momchil Tsanov on 1.01.25.
//
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
po build(int zakach) {
    if (root == NULL) {
        cout << "Задавам корен: " << zakach << endl;
        root = new node;
        root->data = zakach;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else {
        po loc = root;
        po insert = NULL;
        int checks = 0;

        while (loc != NULL) {
            checks++;
            if (zakach == loc->data) {
                cout << "Това вече го има: " << zakach << " (проверки: " << checks << ")" << endl;
                return loc;
            }
            insert = loc;
            if (zakach < loc->data) {
                loc = loc->left;
            } else {
                loc = loc->right;
            }
        }

        cout << "Добавям: " << zakach << " (проверки: " << checks << ")" << endl;
        loc = new node;
        loc->data = zakach;
        loc->left = NULL;
        loc->right = NULL;

        if (zakach < insert->data) {
            insert->left = loc;
        } else {
            insert->right = loc;
        }
        return loc;
    }
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

void infixPrint(po root) {
    if (root != NULL) {
        infixPrint(root->left);
        cout << root->data << " ";
        infixPrint(root->right);
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

int main() {
    int number;
    char answer;

    cout << "Въведи числата: ";
    for (int i = 0; i < 7; i++) {
        cin >> number;
        build(number);
    }

    cout << endl;
    cout << "Краен вид на дървото:\n";
    print(root, 5);
    cout << endl;

    cout << "Инфиксно обхождане: ";
    infixPrint(root);
    cout << endl;

    cout << "Ще търсиш ли? (y/n): ";
    cin >> answer;
    while (answer != 'n') {
        cout << "Какво търсиш?: ";
        cin >> number;
        find(number);

        cout << "Ще търсиш ли? (y/n): ";
        cin >> answer;
    }

    return 0;
}
