#include "../view.h"
#include "../../../lib.h"
#include "../../../Domain/domain.h"

void testFindMin() {
    vector<int> intVec = { 3, 1, 4, 1, 5 };
    vector<string> strVec = { "apple", "orange", "banana" };
    vector<char> charVec = { 'z', 'a', 'm' };

    findMin<int> intMin;
    findMin<string> strMin;
    findMin<char> charMin;

    cout << "findMin<int>: " << intMin(intVec) << endl; // Expected: 1
    cout << "findMin<string>: " << strMin(strVec) << endl; // Expected: apple
    cout << "findMin<char>: " << charMin(charVec) << endl; // Expected: a
}

void testFindMax() {
    vector<int> intVec = { 3, 1, 4, 1, 5 };
    vector<string> strVec = { "apple", "orange", "banana" };
    vector<char> charVec = { 'z', 'a', 'm' };

    findMax<int> intMax;
    findMax<string> strMax;
    findMax<char> charMax;

    cout << "findMax<int>: " << intMax(intVec) << endl; // Expected: 5
    cout << "findMax<string>: " << strMax(strVec) << endl; // Expected: orange
    cout << "findMax<char>: " << charMax(charVec) << endl; // Expected: z
}

void testSortAscending() {
    vector<int> intVec = { 3, 1, 4, 1, 5 };
    vector<string> strVec = { "apple", "orange", "banana" };
    vector<char> charVec = { 'z', 'a', 'm' };

    sortAscending<int> intSort;
    sortAscending<string> strSort;
    sortAscending<char> charSort;

    intSort(intVec);
    strSort(strVec);
    charSort(charVec);

    cout << "sortAscending<int>: ";
    for (int i : intVec) cout << i << " "; // Expected: 1 1 3 4 5
    cout << endl;

    cout << "sortAscending<string>: ";
    for (string s : strVec) cout << s << " "; // Expected: apple banana orange
    cout << endl;

    cout << "sortAscending<char>: ";
    for (char c : charVec) cout << c << " "; // Expected: a m z
    cout << endl;
}

void testSortDescending() {
    vector<int> intVec = { 3, 1, 4, 1, 5 };
    vector<string> strVec = { "apple", "orange", "banana" };
    vector<char> charVec = { 'z', 'a', 'm' };

    sortDescending<int> intSort;
    sortDescending<string> strSort;
    sortDescending<char> charSort;

    intSort(intVec);
    strSort(strVec);
    charSort(charVec);

    cout << "sortDescending<int>: ";
    for (int i : intVec) cout << i << " "; // Expected: 5 4 3 1 1
    cout << endl;

    cout << "sortDescending<string>: ";
    for (string s : strVec) cout << s << " "; // Expected: orange banana apple
    cout << endl;

    cout << "sortDescending<char>: ";
    for (char c : charVec) cout << c << " "; // Expected: z m a
    cout << endl;
}

void testIncrease() {
    vector<int> intVec = { 1, 2, 3 };
    vector<char> charVec = { 'a', 'b', 'c' };

    increase<int> intInc(2);
    increase<char> charInc(1);

    intInc(intVec);
    charInc(charVec);

    cout << "increase<int>: ";
    for (int i : intVec) cout << i << " "; // Expected: 3 4 5
    cout << endl;

    cout << "increase<char>: ";
    for (char c : charVec) cout << c << " "; // Expected: b c d
    cout << endl;
}

void testDecrease() {
    vector<int> intVec = { 3, 4, 5 };
    vector<char> charVec = { 'b', 'c', 'd' };

    decrease<int> intDec(2);
    decrease<char> charDec(1);

    intDec(intVec);
    charDec(charVec);

    cout << "decrease<int>: ";
    for (int i : intVec) cout << i << " "; // Expected: 1 2 3
    cout << endl;

    cout << "decrease<char>: ";
    for (char c : charVec) cout << c << " "; // Expected: a b c
    cout << endl;
}

void testRemove() {
    vector<int> intVec = { 1, 2, 3 };
    vector<string> strVec = { "apple", "banana", "orange" };
    vector<char> charVec = { 'a', 'b', 'c' };

    removeItem<int> intRem(2);
    removeItem<string> strRem("banana");
    removeItem<char> charRem('b');

    intRem(intVec);
    strRem(strVec);
    charRem(charVec);

    cout << "remove<int>: ";
    for (int i : intVec) cout << i << " "; // Expected: 1 3
    cout << endl;

    cout << "remove<string>: ";
    for (string s : strVec) cout << s << " "; // Expected: apple orange
    cout << endl;

    cout << "remove<char>: ";
    for (char c : charVec) cout << c << " "; // Expected: a c
    cout << endl;
}

void View::Intro0() {
    testFindMin();
    testFindMax();
    testSortAscending();
    testSortDescending();
    testIncrease();
    testDecrease();
    testRemove();
}