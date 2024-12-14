#include <iostream>
#include <limits> // за std::numeric_limits
using namespace std;

int COUNT;
typedef struct node *po;

struct node {
int data;
po left;
po right;
};

po root = NULL;

po build(int zakach) {
if (root == NULL) {
cout << "Zakacham koren " << endl;
root = new node;
root->data = zakach;
root->left = NULL;
root->right = NULL;
return root;
} else {
po loc = root;
po insert;
while (loc != NULL && loc->data != zakach) {
insert = loc;
if (zakach > loc->data) {
loc = loc->right;
} else {
loc = loc->left;
}
}
if (loc == NULL) {
cout << "Zakacham " << endl;
loc = new node;
loc->data = zakach;
loc->left = NULL;
loc->right = NULL;
if (zakach < insert->data) {
insert->left = loc;
} else {
insert->right = loc;
}
} else {
cout << "Divako, tova go ima veche " << zakach << endl;
}
return loc;
}
}

po find(int turseno) {
po loc = root;
while (loc != NULL && loc->data != turseno) {
cout << "vuzel: " << loc->data << endl;
if (turseno > loc->data) { // slizame nadolu
loc = loc->right; // slizam nadqsno
cout << "Slizam nadqsno " << endl;
}
else {
loc = loc->left; //slizam nalqvo
cout << "Slizam nalqvo " << endl;
}
}
if (loc == NULL) {
cout << "Nqma go tursenoto";
}
else {
cout << "Namerih " << turseno << endl;
}
return loc;
}


void infixPrint(po root) {
if (root != NULL) {
infixPrint(root->left);
cout << root->data << " ";
infixPrint(root->right);
} else {
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

int main() {
char answer;
int x;
cout << "She vmukvash li? (y/n): ";
cin >> answer;
while (answer != 'n') {
cout << "Kakvo?: ";
cin >> x;
cout << endl;
build(x);
cout << endl;
cout << "She vmukvash li? (y/n): ";
cin >> answer;
}



cout << "Finalno durvo:\n";
print(root, 5);

cout << "\nInfix: ";
infixPrint(root);
cout << endl;

cout << "She tyrshish li? (y/n): ";
cin >> answer;
while (answer != 'n') {
cout << "Kakvo dirish?: ";
cin >> x;
cout << endl;
find(x);
cout << endl;
cout << "She tyrshish li? (y/n): ";
cin >> answer;
}


return 0;
}