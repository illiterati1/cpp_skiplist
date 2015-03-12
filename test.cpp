#include <iostream>
#include "Skiplist.h"

using namespace std;

int main()
{
    int choice;
    Skiplist<int> skiplist;
    while (true)
    {
        cout << ">> ";
        cin >> choice;
        cin.ignore();
        if (choice == -1)
            break;

        if (skiplist.contains(choice))
            skiplist.remove(choice);
        else
            skiplist.add(choice);
        skiplist.test_print();
    }
}