//
// Created by Momchil Tsanov on 27.11.24.
//

#include <iostream>
#include <cstdlib>

using namespace std;

struct stack_list {
    char letter;
    stack_list* next;
};


void push(stack_list** top, const char value) {
    stack_list* newElement = static_cast<stack_list*>(malloc(sizeof(stack_list)));
    //malloc ще е null ако не се задели успешно памет
    if (newElement == NULL) {
        std::cerr << "Грешка при заделяне на памет!" << std::endl;
        return;
    }
    newElement->letter = value; // Попълване на стойността на елемента
    newElement->next = *top; // Насочване на next да сочи към върха на стека
    *top = newElement; // Обновяване на указателя на стека да сочи към новия елемент, който току-що е добавен
}


char pop(stack_list** top) { //указател към указателя на върха на стека
    if (*top == NULL) {
        std::cerr << "Стекът е празен!" << std::endl;
        return '\0';
    }

    stack_list* temp = *top;
    char poppedValue = temp->letter; // Запазваме стойността
    *top = (*top)->next; // Обновяване на указателя на стека
    free(temp); // Освобождаване на паметта за премахнатия елемент
    return poppedValue;
}

void displayStack(stack_list* top) {
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
void printsStackNaopaki(stack_list* tuk) {
    if (tuk->next != NULL) {
        printsStackNaopaki(tuk->next);
    } else {
        cout << "krai" << endl;
    }
    cout << tuk->letter << " ";
}

int main() {
    stack_list* L = NULL;

    push(&L, 'A');
    push(&L, 'B');
    push(&L, 'C');
    push(&L, 'd');
    push(&L, 'e');
    push(&L, 'b');
    push(&L, 'g');

    displayStack(L);




    std::cout << "Премахнат елемент: " << pop(&L) << std::endl;
    std::cout << "Премахнат елемент: " << pop(&L) << std::endl;

    displayStack(L);


    printsStackNaopaki(L);

    // while (L != NULL) {
    //     pop(&L);
    // }


    return 0;
}
