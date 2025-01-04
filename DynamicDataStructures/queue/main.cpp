#include <iostream>
#include <cstdlib>

struct queue {
    char letter;
    queue* next;
};

void push(queue** front, queue** rear, const char value) {
    auto* newElement = static_cast<queue*>(malloc(sizeof(queue)));

    if (newElement == NULL) {
        std::cerr << " neuspeshno zadelenq pamet!" << std::endl;
        return;
    }

    newElement->letter = value;
    newElement->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newElement;
    }
    else {
        (*rear)->next = newElement;
        *rear = newElement;
    }
}

char pop(queue** front) {
    if (*front == NULL) {
        std::cerr << "Queue is empty!" << std::endl;
        return '\0';
    }

    queue* temp = *front;
    char dequeuedValue = temp->letter;
    *front = (*front)->next;

    if (*front == NULL) {
        std::cerr << " Spisuka e prazen" << std::endl;
    }

    free(temp);
    return dequeuedValue;
}

void displayQueue(queue* front) {
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
    queue* front = NULL;
    queue* rear = NULL;

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
