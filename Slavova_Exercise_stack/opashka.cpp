#include <iostream>
#include <ctype.h>
using namespace std;

typedef struct kutiq* p;

struct kutiq {
    p next;
    char letter;
};

int main() {
    p end = NULL;
    p beg = NULL;
    p vkarai;
    char neshto = 'a';
    while (isalpha(neshto)) {
        vkarai = new kutiq;
        neshto = cin.get();
        vkarai->letter = neshto;
        vkarai->next = NULL;
        if (beg == NULL) {
            beg = vkarai;
            end = vkarai;
        } else {
            end->next = vkarai;
            end = vkarai;
        }
    }
    p iterator = beg;
    while (iterator != NULL) {
        cout << iterator->letter << " ";
        iterator = iterator->next;
    }

    return 0;
}
