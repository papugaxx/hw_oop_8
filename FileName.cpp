#include <iostream>
#include "Array.h"

using namespace std;

int main() {
    Array<int> arr;

    if (arr.IsEmpty()) {
        cout << "Array is empty\n";
    }
    else {
        cout << "Array is not empty\n";
    }

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    cout << "Added elements: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr.GetAt(i) << " ";
    }
    cout << endl;

    arr.InsertAt(1, 15);
    cout << "After insert: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr.GetAt(i) << " ";
    }
    cout << endl;

    arr.RemoveAt(2);
    cout << "After remove: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr.GetAt(i) << " ";
    }
    cout << endl;

    cout << "Last: " << arr.GetAt(arr.GetSize() - 1) << endl;

    Array<int> otherArr;
    otherArr.Add(100);
    otherArr.Add(200);

    arr.Append(otherArr);
    cout << "After append: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr.GetAt(i) << " ";
    }
    cout << endl;

    Array<int> copiedArr;
    copiedArr = arr;
    cout << "Copied array: ";
    for (int i = 0; i < copiedArr.GetSize(); i++) {
        cout << copiedArr.GetAt(i) << " ";
    }
    cout << endl;

    arr.RemoveAll();
    cout << "After clear: ";
    if (arr.IsEmpty()) {
        cout << "Array is empty\n";
    }
    else {
        cout << "Array is not empty\n";
    }

    return 0;
}
