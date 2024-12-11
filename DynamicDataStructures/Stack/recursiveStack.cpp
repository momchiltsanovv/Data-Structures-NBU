//
// Created by Momchil Tsanov on 27.11.24.
//

#include <iostream>
#include <cstdlib>

using namespace std;

struct linked_list {
    char letter;
    linked_list* next;
};


void push(linked_list** head, const char value) {
    linked_list* newElement = static_cast<linked_list*>(malloc(sizeof(linked_list)));
    //malloc ще е null ако не се задели успешно памет
    if (newElement == NULL) {
        std::cerr << "Грешка при заделяне на памет!" << std::endl;
        return;
    }
    newElement->letter = value; // Попълване на стойността на елемента
    newElement->next = *head; // Насочване на next да сочи към върха на стека
    *head = newElement; // Обновяване на указателя на стека да сочи към новия елемент, който току-що е добавен
}


char pop(linked_list** top) { //указател към указателя на върха на стека
    if (*top == NULL) {
        std::cerr << "Стекът е празен!" << std::endl;
        return '\0';
    }

    linked_list* temp = *top;
    char poppedValue = temp->letter; // Запазваме стойността
    *top = (*top)->next; // Обновяване на указателя на стека
    free(temp); // Освобождаване на паметта за премахнатия елемент
    return poppedValue;
}

void displayStack(linked_list* top) {
    if (top == NULL) {
        std::cout << "Стекът е празен!" << std::endl;
        return;
    }

    std::cout << "Елементи в стека: ";
    while (top != NULL) {
        std::cout << top->letter << " ";
        top = top->next;
    }
    std::cout << std::endl;
}
void printsStackNaopaki(linked_list* tuk) {
    if (tuk->next != NULL) {
        printsStackNaopaki(tuk->next);
    } else {
        cout << "krai" << endl;
    }
    cout << tuk->letter << " ";
}

int main() {
    linked_list* L = NULL;

    push(&L, 'M');
    push(&L, 'o');
    push(&L, 'm');
    push(&L, 'c');
    push(&L, 'h');
    push(&L, 'i');
    push(&L, 'l');

    displayStack(L);
    printsStackNaopaki(L);

    // while (L != NULL) {
    //     pop(&L);
    // }


    return 0;
}
