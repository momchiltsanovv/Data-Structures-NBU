#include <iostream>
#include <cstdlib>

struct linked_list {
    int num;
    linked_list* next;
};

void insert(linked_list** head, const int value) {
    auto* newElement = static_cast<linked_list*>(malloc(sizeof(linked_list)));
    if (newElement == NULL) {
        std::cerr << "Грешка при заделяне на памет!" << std::endl;
        return;
    }
/*
    X→value>=right→value
    &&
    right→ value!=NULL
 */


    if () {
        *head = newElement;
        return;
    }

    linked_list* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newElement;
}

void displayList(linked_list* head) {
    if (head == NULL) {
        std::cout << "Свързаният списък е празен!" << std::endl;
        return;
    }

    std::cout << "Елементи в свързания списък: ";
    while (head != NULL) {
        std::cout << head->num << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void freeList(linked_list** head) {
    while (*head != NULL) {
        linked_list* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    linked_list* L = NULL;


    insert(&L, 1);
    insert(&L, 3);
    insert(&L, 5);
    insert(&L, 6);
    insert(&L, 9);
    insert(&L, 8);
    insert(&L, 2);

    displayList(L);

    freeList(&L);

    displayList(L);

    return 0;
}
