//
// Created by Momchil Tsanov on 7.12.24.
//


#include <iostream>
using namespace std;

typedef struct element* po;

struct element {
    po next;
    int data;
};

int main() {
    po na = NULL;
    po p;
    po contr;
    int x = 1;
    while (x != 0) {
        cout << "Enter a positive number: ";
        cin >> x;
        p = new element;
        p->data = x;
        p->next = na;
        if (na == NULL || na->data >= x) {
            na = p;
        }
        else {
            contr = na;
            while (contr->next != NULL && contr->next->data < x) {
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
    return 0;
}
