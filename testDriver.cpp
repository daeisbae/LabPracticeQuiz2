#include <iostream>
#include <assert.h>
#include "BST.h"
using namespace std;

void test_nodesCount() {
    cout << "Testing nodesCount()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();
    assert(bst->nodesCount() == 0);

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    assert(bst->nodesCount() == 3);
    delete bst;
    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();

    bst2->insert(55);
    bst2->insert(31);

    assert(bst2->nodesCount() == 2);

    bst2->insert(77);
    bst2->insert(33);

    assert(bst2->nodesCount() == 4);
    delete bst2;

    cout << "Passed!" << endl;

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(1);
    bst3->insert(2);

    assert(bst3->nodesCount() == 2);
    delete bst3;
    cout << "Passed!" << endl;

    cout << "Testing nodesCount() Passed" << endl << endl;
}

void test_min() {
    cout << "Testing min()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    assert(bst->min() == 3);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->min();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);

    assert(bst3->min() == 1);
    delete bst3;
    cout << "Passed!" << endl;

    cout << "Testing min() Passed" << endl << endl;
}

void test_evenCount() {
    cout << "Testing evenCount()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    assert(bst->evenCount() == 0);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->evenCount();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);

    assert(bst3->evenCount() == 3);
    delete bst3;
    cout << "Passed!" << endl;

    cout << "Testing evenCount() Passed" << endl << endl;
}

void test_oddCount() {
    cout << "Testing oddCount()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(2);
    bst->insert(4);
    bst->insert(0);

    assert(bst->oddCount() == 0);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->oddCount();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);

    assert(bst3->oddCount() == 4);
    delete bst3;
    cout << "Passed!" << endl;

    cout << "Testing oddCount() Passed" << endl << endl;
}

void test_duplicateCount() {
    cout << "Testing duplicateCount()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);
    bst->insert(5);

    assert(bst->duplicateCount(5) == 2);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->duplicateCount(1);    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);
    bst3->insert(5);
    bst3->insert(7);

    assert(bst3->duplicateCount(7) == 2);
    delete bst3;
    cout << "Passed!" << endl;

    // Test 4
    cout << "Part 4: ";
    BST* bst4 = new BST();
    bst4->insert(5);
    bst4->insert(3);
    bst4->insert(7);

    assert(bst4->duplicateCount(1) == 0);
    delete bst4;
    cout << "Passed!" << endl;

    cout << "Testing duplicateCount() Passed" << endl << endl;
}

void test_height() {
    cout << "Testing height()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    assert(bst->height() == 2);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->height();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(4);
    bst3->insert(1);

    assert(bst3->height() == 4);
    delete bst3;
    cout << "Passed!" << endl;

    cout << "Testing height() Passed" << endl << endl;
}

void test_sum() {
    cout << "Testing sum()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    assert(bst->sum() == 15);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->sum();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);

    assert(bst3->sum() == 28);
    delete bst3;
    cout << "Passed!" << endl;

    // Test 4
    cout << "Part 4: ";
    BST* bst4 = new BST();
    bst4->insert(0);
    bst4->insert(1);
    assert(bst4->sum() == 1);
    delete bst4;
    cout << "Passed!" << endl;

    cout << "Testing sum() Passed" << endl << endl;
}

void test_average() {
    cout << "Testing average()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    assert(bst->average() == (double)5);
    delete bst;

    cout << "Passed!" << endl;

    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->average();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);

    assert(bst3->average() == (double)4);
    delete bst3;
    cout << "Passed!" << endl;

    // Test 4
    cout << "Part 4: ";
    BST* bst4 = new BST();
    bst4->insert(0);
    bst4->insert(1);
    assert(bst4->average() == 0.5);
    delete bst4;
    cout << "Passed!" << endl;

    cout << "Testing average() Passed" << endl << endl;
}

void test_printInReverseOrder() {
    cout << "Testing printInReverseOrder()..." << endl;
    // Test 1
    cout << "Part 1: ";
    BST* bst = new BST();

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);

    bst->printInReverseOrder();
    cout << endl;
    delete bst;


    // Test 2
    cout << "Part 2: ";
    BST* bst2 = new BST();
    try {
        bst2->printInReverseOrder();    
    }
    catch (EmptyDataCollectionException& e) {
        delete bst2;
        cout << "Passed!" << endl;
    }

    // Test 3
    cout << "Part 3: ";
    BST* bst3 = new BST();
    bst3->insert(5);
    bst3->insert(3);
    bst3->insert(7);
    bst3->insert(2);
    bst3->insert(4);
    bst3->insert(6);
    bst3->insert(1);

    bst3->printInReverseOrder();
    cout << endl;
    delete bst3;
    cout << "Passed!" << endl;

    // Test 4
    cout << "Part 4: ";
    BST* bst4 = new BST();
    bst4->insert(0);
    bst4->insert(1);

    bst4->printInReverseOrder();
    cout << endl;
    delete bst4;
    cout << "Passed!" << endl;

    cout << "Testing printInReverseOrder() Passed" << endl << endl;
}

int main() {
    test_nodesCount();
    test_min();
    test_evenCount();
    test_oddCount();
    test_duplicateCount();
    test_height();
    test_sum();
    test_average();
    test_printInReverseOrder();
    return 0;
}