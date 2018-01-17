#include "characterarray.h"

CharacterArray::CharacterArray()
{
    _cap = INITIAL_CAPACITY;
    _char_array = new char[_cap];
    _char_array[0] = '\0';
    _elements = 0;
}

CharacterArray::CharacterArray(char* str, int length)
{
    _cap = INITIAL_CAPACITY;
    _elements = length;
    while(_cap <= _elements){
        _resize_array();
    }
    for(int i = 0; i < length; i++){
        _char_array[i] = str[i];
    }
    _char_array[length] = '\0';
}

CharacterArray::~CharacterArray()
{
    delete[] _char_array;
}

void CharacterArray::append(char c) {
    if(_elements >= _cap){
        _resize_array();
    }
    _char_array[length()] += c;
    _elements++;
}

void CharacterArray::insert(char c, int index) {
    if(_elements >= _cap){
        _resize_array();
    }

    while(index >= 0){
        if(_char_array[index] > c){
            _char_array[index + 1] = _char_array[index];
            index--;
        }
        else{
            break;
        }
    }

    _char_array[index + 1] = c;
    _elements++;
}

void CharacterArray::setAt(char c, int index) {
    _char_array[index] = c;
}

char CharacterArray::getAt(int index) {
    return _char_array[index];
}

char CharacterArray::pop_back() {

    //Example of throwing an exception
    if(isEmpty()) {
        throw EmptyException();
    }

    char temp = _char_array[_elements - 1];
    _char_array[_elements - 1] = '\0';
    _elements--;
    return temp; //change or remove this line
}

char CharacterArray::removeAt(int index) {
    char temp = _char_array[index];
    for(int i = _elements - 1; i >= index; i--){
        _char_array[index] = _char_array[index + 1];
    }
    _char_array[_elements - 1] = '\0';
    _elements--;
    return temp;
}

void CharacterArray::clear() {
    _char_array[0] = '\0';
    _elements = 0;
}

int CharacterArray::length() {
    return _elements;
}

bool CharacterArray::isEmpty() {
    if(strlen(_char_array) == 0){
        return true;
    }
    return false;
}

char* CharacterArray::substring(int startIndex, int length) {
    char substring[length + 1];
    int j = 0;
    for(int i = startIndex; i < startIndex + length; i++){
        substring[j] = _char_array[i];
        j++;
    }
    substring[length + 1] = '\0';
    return substring;
}

ostream& operator <<(ostream& out, const CharacterArray& ca) {
    for(int i = 0; i < ca._cap; i++){
        out << ca._char_array[i];
    }
    return out;
}

void CharacterArray::_resize_array(){
    _cap *= 2;
    char* temp_array = new char[_cap];

    for(int i = 0; i < _cap; i++){
        temp_array[i] = _char_array[i];
    }
    delete[] _char_array;
    _char_array = temp_array;
}
