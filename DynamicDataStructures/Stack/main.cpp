//
// Created by Momchil Tsanov on 20.11.24.
//

#include <iostream>

using namespace std;

struct list {
    int value;
    list* next;

};

void push(list* L, int num) {
    L = nullptr;

    list* temp;
    temp = new list;
    temp->next = nullptr;
    temp->value = num;
}

int main() {


    return 0;
}

