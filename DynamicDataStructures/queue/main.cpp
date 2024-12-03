//
// Created by Momchil Tsanov on 27.11.24.
//

#include <iostream>
#include <cstdlib>

struct queue_node {
    char letter;
    queue_node* next;
};

void push(queue_node** front, queue_node** rear, const char value) {
    auto* newElement = static_cast<queue_node*>(malloc(sizeof(queue_node)));

    if (newElement == NULL) {
        std::cerr << "Memory allocation error!" << std::endl;
        return;
    }

    newElement->letter = value; // попълване на стойността на новия елемент
    newElement->next = NULL; // следвашия елемент ТРЯБВА да е NULL

    if (*rear == NULL) {
        // Ако е празeн и front и rear ще сочат към новия елемент
        *front = *rear = newElement;
    }
    else {
        // насочване на новия елемент към rear и обновяване на rear
        (*rear)->next = newElement;
        *rear = newElement;
    }
}

char pop(queue_node** front) {
    if (*front == NULL) {
        std::cerr << "Queue is empty!" << std::endl;
        return '\0';
    }

    queue_node* temp = *front;
    char dequeuedValue = temp->letter; //запазвам стойносттайй
    *front = (*front)->next; // преместване на front към следващия елемент


    if (*front == NULL) {
        std::cerr << "Queue is now empty!" << std::endl;
    }

    free(temp);
    return dequeuedValue;
}

void displayQueue(queue_node* front) {
    if (front == NULL) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }

    std::cout << "Elements in the queue: ";
    while (front != NULL) {
        std::cout << front->letter << " ";
        front = front->next;
    }
    std::cout << std::endl;
}

int main() {
    queue_node* front = NULL;
    queue_node* rear = NULL;

    push(&front, &rear, 'A');
    push(&front, &rear, 'B');
    push(&front, &rear, 'C');
    push(&front, &rear, 'd');
    push(&front, &rear, 'e');
    push(&front, &rear, 'b');
    push(&front, &rear, 'g');

    displayQueue(front);

    std::cout << "Dequeued element: " << pop(&front) << std::endl;
    std::cout << "Dequeued element: " << pop(&front) << std::endl;

    displayQueue(front);

    while (front != NULL) {
        pop(&front);
    }

    displayQueue(front);

    return 0;
}
