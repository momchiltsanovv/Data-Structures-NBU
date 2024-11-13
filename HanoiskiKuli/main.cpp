//
// Created by Momchil Tsanov on 13.11.24.
//

#include <iostream>
#include <vector>

using namespace std;

void displayPegs(const vector<int>& from, const vector<int>& to, const vector<int>& help) {
    cout << "Segashen vid:" << endl;
    cout << "Peg A: ";
    for (int disk : from) {
        cout << disk << " ";
    }
    cout << endl;

    cout << "col B: ";
    for (int disk : help) {
        cout << disk << " ";
    }
    cout << endl;

    cout << "col C: ";
    for (int disk : to) {
        cout << disk << " ";
    }
    cout << endl << "------------------------" << endl;
}

void hanoi(int size, vector<int>& from, vector<int>& to, vector<int>& help) {
    if (size == 1) {
        to.push_back(from.back());
        from.pop_back();
        cout << "Premesti edin disk ot A na C" << endl;
        displayPegs(from, to, help);
    } else {
        hanoi(size - 1, from, help, to);

        to.push_back(from.back());
        from.pop_back();
        cout << "Premesti edin disk ot A na C" << endl;
        displayPegs(from, to, help);

        hanoi(size - 1, help, to, from);
    }
}

int main() {
    int numberOfDisks = 4;
    vector<int> pegA, pegB, pegC;

    for (int i = numberOfDisks; i >= 1; --i) {
        pegA.push_back(i);
    }

    displayPegs(pegA, pegB, pegC);

    hanoi(numberOfDisks, pegA, pegC, pegB);

    return 0;
}

