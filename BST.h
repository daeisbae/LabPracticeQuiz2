/*
 * BST.h
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: Feb. 2022
 */

#pragma once

#include "BSTNode.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"


class BST {
	
private:

	// You cannot change the following data members of this class.
	BSTNode* root; 
    unsigned int elementCount;           

    /* Utility methods */

	// Feel free to add private methods to this class.
	
	// Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    bool insertR(const int& element, BSTNode* current); 

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    int& retrieveR(const int& targetElement, BSTNode* current) const;

	// Description: Recursive in order traversal of a binary search tree.	
	void traverseInOrderR(void visit(const int&), BSTNode* current) const;

	// Remove nodes from the tree from the bottom.
	void removeAll(BSTNode* element);

	void makeNodeIfEmpty(BSTNode* current, const int& targetElement, const bool isLeft);

	// If element found, increase 1 to elementCount
	void elementCounter(int& targetElement);


	unsigned int duplicateCountR(BSTNode* current, const int targetElement);

	int nodesCountR(BSTNode* current) const;

	int evenCountR(BSTNode* current) const;

	int oddCountR(BSTNode* current) const;

	int heightR(BSTNode* current) const;

	int sumR(BSTNode* current) const;

	void printInReverseOrderR(BSTNode* current) const;
         
		 
public:

	// You cannot change the prototype of the public methods of this class.
	// Remember, if you add public methods to this class, our test driver 
	// - the one we will use to mark this assignment - will not know about them
	// since we will use these public method prototypes to create our test driver.

    /* Constructors and destructor */
	BST();                               // Default constructor
    BST(int& element);           // Parameterized constructor 
	BST(const BST& aBST);   // Copy constructor 
    ~BST();                              // Destructor 
	
	/* Getters and setters */
	unsigned int getElementCount() const;
/*
	getRoot() and setRoot(...) <- are not acceptable getter/setter - can you see why?
	setElementCount(...) <- is not an acceptable setter - can you see why?
*/

    /* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
	void insert(const int& newElement);	
	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
	int& retrieve(const int& targetElement) const;
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)	
	void traverseInOrder(void visit(const int&)) const;
	
	// Description: Counts the number of nodes in the binary search tree without using elementCount.
	// Precondition: Binary search tree is not empty.
	// Time efficiency: O(n)
	int nodesCount() const;

	// Description: Find the minimum value in the binary search tree.
	// Precondition: Binary search tree is not empty.
	// Time efficiency: O(log2 n)
	int min() const;

	int minR(BSTNode* current) const;

	// Description: Find the number of even values in the binary search tree.
	// Precondition: Binary search tree is not empty. and all elements are integers.
	// Time efficiency: O(n)
	int evenCount() const;

	// Description: Find the number of odd values in the binary search tree.
	// Precondition: Binary search tree is not empty.
	// Time efficiency: O(n)
	int oddCount() const;

	// Description: This method returns the number of times targetElement is found in a BST.
	// Precondition: Binary search tree is not empty.
	// Time efficiency: O(n)
	unsigned int duplicateCount(const int targetElement);

	// Description: Get the height of the tree.
	// Precondition: Binary search tree is not empty.
	// Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Time efficiency: O(n)
	int height() const;

	// Description: Get the sum of all the values in the tree.
	// Precondition: Binary search tree is not empty.
	// Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Time efficiency: O(n)
	int sum() const;

	// Description: Get the average of all the values in the tree.
	// Precondition: Binary search tree is not empty.
	// Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Time efficiency: O(n)
	double average() const;


	// Description: prints the content of a BST in reverse order
	// Precondition: Binary search tree is not empty.
	// Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Time efficiency: O(n)
	void printInReverseOrder() const;


	// Description: Removes the node with the targetElement from the BST.
	// Precondition: Binary search tree is not empty.
	// Exception: Throws the exception "EmptyDataCollectionException"
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException"
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
	void remove(const int targetElement);


}; // end BST

#include "BST.cpp"  // Including "BST.cpp" (instead of copying the content of BST.cpp) is another way of creating templates.