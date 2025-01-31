//
// Created by Momchil Tsanov on 23.01.25.
//
#include <iostream>
using namespace std;

struct element {
    int data;
    element* left;
    element* right;
};

element * ibd(int n) {
    int d = 0;
    if(n> 0){
        element* p;
        p = new element;
        p->left = ibd(n/2);

        cin >> d;
        p->data = d;
        p->right = ibd(n - n/2 - 1);
        return p;
    }
    else {
        return NULL;
    }
}
void print(const element* root, int space) {
    int count = 10;
    if (root == NULL)
        return;

    space += count;
    print(root->right, space);
    cout << endl;

    for (int i = count; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print(root->left, space);
}

int main(){
    int n;
    cin >> n;
    element* root = ibd(n);
    print(root, 5);
  }