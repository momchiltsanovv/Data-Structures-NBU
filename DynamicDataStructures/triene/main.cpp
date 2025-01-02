#include <iostream>

using namespace std;

int COUNT;
typedef struct node* po;

struct node {
    int data;
    po left;
    po right;
};

po root = NULL;

po findAndBuild(int turseno) {
    if (root == NULL) {
        cout << "Zakacham koren " << endl;
        root = new node;
        root->data = turseno;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else {
        po loc = root;
        po insert = NULL;
        while (loc != NULL && loc->data != turseno) {
            insert = loc;
            if (turseno > loc->data) {
                loc = loc->right;
            }
            else {
                loc = loc->left;
            }
        }
        if (loc == NULL) {
            cout << "Zakacham " << endl;
            loc = new node;
            loc->data = turseno;
            loc->left = NULL;
            loc->right = NULL;
            if (turseno < insert->data) {
                insert->left = loc;
            }
            else {
                insert->right = loc;
            }
        }
        else {
            cout << "Namerih " << turseno << endl;
        }
        return loc;
    }
}


void infixPrint(po root) {
    if (root != NULL) {
        infixPrint(root->left);
        cout << root->data << " ";
        infixPrint(root->right);
    }
    else {
        cout << " ";
    }
}


void print(po root, int space) {
    COUNT = 10;
    if (root == NULL)
        return;

    space += COUNT;
    print(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print(root->left, space);
}

void trii(int toDel) {
    po loc = root; // Позиция на елемента за триене (ако го намерим)
    po tati = NULL; // "Татко" = родител на loc
    po pomosht = NULL;
    po del = NULL;

    // 1) Търсим елемента, който ще трием
    while (loc != NULL && loc->data != toDel) {
        tati = loc;
        if (toDel > loc->data) {
            loc = loc->right;
        }
        else {
            loc = loc->left;
        }
    }

    // Ако такъв елемент няма в дървото, приключваме
    if (loc == NULL) {
        cout << "Nqma takuv element\n";
        return;
    }

    //
    // 2) Проверяваме колко деца има loc
    //

    // ----- Случай A: Няма деца (loc е лист) -----
    if (loc->left == NULL && loc->right == NULL) {
        del = loc;

        // Ако loc не е корен
        if (tati != NULL) {
            // "Откачаме" го от родителя
            if (tati->left == loc)
                tati->left = NULL;
            else
                tati->right = NULL;
        }
        else {
            // Ако loc е корен, дървото става празно
            root = NULL;
        }

        delete del;
    }
    // ----- Случай B: Точно 1 дете -----
    else if (loc->left == NULL || loc->right == NULL) {
        // Намираме кое дете съществува (лявото или дясното)
        po child = (loc->left != NULL) ? loc->left : loc->right;

        // Ако loc не е корен
        if (tati != NULL) {
            if (tati->left == loc)
                tati->left = child;
            else
                tati->right = child;
        }
        else {
            // loc е корен, пренасочваме root към child
            root = child;
        }

        delete loc;
    }
    // ----- Случай C: Две деца -----
    else {
        // Ще заместим loc->data с "най-големия" елемент от лявото поддърво
        // (може да използваме и "най-малкия" елемент от дясното поддърво, без значение).
        pomosht = loc->left;
        po parentOfPomosht = loc; // родител на pomosht

        // Търсим най-дясното дете в лявото поддърво
        while (pomosht->right != NULL) {
            parentOfPomosht = pomosht;
            pomosht = pomosht->right;
        }

        // Копираме стойността от pomosht в loc
        loc->data = pomosht->data;

        // Сега изтриваме pomosht (той има най-много ляво дете)
        if (parentOfPomosht->right == pomosht)
            parentOfPomosht->right = pomosht->left;
        else
            parentOfPomosht->left = pomosht->left;

        delete pomosht;
    }
}

int main() {
    char answer;
    int x;
    cout << "She tyrshish li? / Vmukvash li? (y/n): ";
    cin >> answer;
    while (answer != 'n') {
        cout << "Kakvo?: ";
        cin >> x;
        cout << endl;
        findAndBuild(x);
        cout << endl;
        cout << "She tyrshish li? / Vmukvash li? (y/n): ";
        cin >> answer;
    }


    cout << "Finalno durvo:\n";
    print(root, 5);

    cout << "\nInfix: ";
    infixPrint(root);
    cout << endl;

    cout << "She triish li?\n";
    cin >> answer;

    while (answer != 'n') {
        cout << "Kogo triesh?\n";
        cin >> x;
        trii(x);
        cout << "Eto durvoto:\n";
        print(root, 5);
        cout << "She triish li?\n";
        cin >> answer;
    }


    return 0;
}
