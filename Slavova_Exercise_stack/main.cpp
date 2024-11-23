#include <iostream>

using namespace std;
typedef struct kutiq* p;

struct kutiq {
    p next;
    char letter;
};


void printsStackNaopaki(p tuk) {

    if (tuk->next != NULL) {
        printsStackNaopaki(tuk->next);
    } else {
        cout << "krai" << endl;
    }
    cout << tuk->letter;

}





int main() {
    p na = NULL;
    p pamet;
    char neshto = 'a';


    while (isalpha(neshto) || neshto == ' ') {
        pamet = new kutiq;
        neshto = cin.get();
        pamet->letter = neshto;
        pamet->next = na;
        na = pamet;
    }

    p help = na;
    na = na->next;
    delete help;
    p iterator = na;

    while (iterator != NULL) {
        //cout << iterator->letter << " ";
        iterator = iterator->next;
    }


    delete iterator;

    printsStackNaopaki(na);

    return 0;
}
