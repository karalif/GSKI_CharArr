#include "characterarray.h"

void printArray(CharacterArray &ca) {

    cout << "printing array" << endl;
    cout << "CharacterArray: \"" << ca << "\"" << endl;
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void append(CharacterArray &ca, char c) {

    cout << "append: '" << c << "'" << endl;
    ca.append(c);
    cout << "CharacterArray: \"" << ca << "\"" << endl;
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void insertIntoArray(CharacterArray &ca, char c, int index) {

    try {
        cout << "insert: '" << c << "' at index: " << index << endl;
        ca.insert(c, index);
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void setAt(CharacterArray &ca, char c, int index) {

    try {
        cout << "set: '" << c << "' at index: " << index << endl;
        ca.setAt(c, index);
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void getAt(CharacterArray &ca, int index) {

    try {
        cout << "get character at index: " << index << endl;
        char c = ca.getAt(index);
        cout << "Returned value: '" << c << "'" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << endl;
}

void popFromArray(CharacterArray &ca) {

    try {
        cout << "popping character from back" << endl;
        char c = ca.pop_back();
        cout << "Returned value: '" << c << "'" << endl;
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (EmptyException e) {
        cout << "array is empty" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void removeAt(CharacterArray &ca, int index) {

    try {
        cout << "remove character at index: " << index << endl;
        char c = ca.removeAt(index);
        cout << "Returned value: '" << c << "'" << endl;
        cout << "CharacterArray: \"" << ca << "\"" << endl;
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << "string length: " << ca.length() << endl;
    cout << endl;
}

void substring(CharacterArray &ca, int s, int l) {

    try {
        cout << "substring from " << s << " of length " << l << endl;
        char* tmp = ca.substring(s, l);
        if(tmp != NULL) {
            cout << "Returned array: \"" << tmp << "\"" << endl;
            delete[] tmp;
        }
        else {
            cout << "Returned array: NULL" << endl;
        }
    }
    catch (IndexOutOfBoundsException e) {
        cout << "index out of bounds" << endl;
    }
    cout << endl;
}

void clearArray(CharacterArray &ca) {

    if(ca.isEmpty()) {
        cout << "array is empty" << endl;
    }
    else {
        cout << "clearing array" << endl;
        ca.clear();
        cout << "CharacterArray: \"" << ca << "\"" << endl;
        cout << "string length: " << ca.length() << endl;
    }
    cout << endl;
}

int main() {

    CharacterArray ca1;

    printArray(ca1);

    insertIntoArray(ca1, 'a', 1);
    insertIntoArray(ca1, 'a', 0);
    insertIntoArray(ca1, 'b', 1);
    insertIntoArray(ca1, 'c', 0);
    insertIntoArray(ca1, 'd', 4);
    insertIntoArray(ca1, ' ', 3);
    insertIntoArray(ca1, 'd', 4);
    insertIntoArray(ca1, 'l', 2);
    insertIntoArray(ca1, 'e', 3);
    insertIntoArray(ca1, 'e', 7);
    insertIntoArray(ca1, 'a', 7);
    insertIntoArray(ca1, 'k', 8);
    insertIntoArray(ca1, 'r', 7);
    insertIntoArray(ca1, 's', -1);

    append(ca1, ' ');
    append(ca1, 'm');
    append(ca1, 'o');
    append(ca1, 'r');
    append(ca1, 'e');
    append(ca1, ' ');
    append(ca1, 's');
    append(ca1, 't');
    append(ca1, 'u');
    append(ca1, 'f');
    append(ca1, 'f');

    setAt(ca1, 'g', 12);

    getAt(ca1, 3);
    getAt(ca1, 12);
    getAt(ca1, 17);
    getAt(ca1, 16);
    getAt(ca1, 9);
    getAt(ca1, 22);
    getAt(ca1, 0);

    append(ca1, ' ');
    append(ca1, 'p');
    append(ca1, 'o');
    append(ca1, 'p');

    popFromArray(ca1);
    popFromArray(ca1);
    popFromArray(ca1);
    popFromArray(ca1);

    removeAt(ca1, 16);
    removeAt(ca1, 5);
    removeAt(ca1, 10);

    cout << endl << endl;

    substring(ca1, 2, 6);
    substring(ca1, 6, 5);
    substring(ca1, 0, 5);
    substring(ca1, 19, 7);
    substring(ca1, -2, 4);
    substring(ca1, 4, 0);

    clearArray(ca1);
    append(ca1, '7');
    append(ca1, '7');
    append(ca1, '7');
    clearArray(ca1);

    //CharacterArray ca2((char*)"parameter constructor", 21);
    //printArray(ca2);

    return 0;
}
