//
// Created by Momchil Tsanov on 7.12.24.
//


#include <iostream>
using namespace std;

typedef struct element* po;

struct element {
    po next;
    char data;
};

int main() {
    po na = NULL;
    po p;
    po contr;
    string name;
    getline(cin, name);
    for (int i = 0; i < name.length(); i++) {
        p = new element;
        p->data = name[i];
        p->next = na;
        if (na == NULL || na->data >= name[i]) {
            na = p;
        }
        else {
            contr = na;
            while (contr->next != NULL && contr->next->data < name[i]) {
                contr = contr->next;
            }
            p->next = contr->next;
            contr->next = p;
        }
    }

    cout << "The list is: ";
    p = na;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    free(p);
    return 0;
}
