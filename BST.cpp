/*
 * BST.cpp
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

#include "BST.h"
#include <iostream>
using namespace std;
	
// You can modify the implementation of these methods, but cannot modify their proptotype.
// However, if you modify the implementation of these methods, your code must still 
// satisfy the documentation contract above each of these methods.

/* Constructors and destructor */

	// Default constructor
	BST::BST() {
		root = NULL;
		elementCount = 0;
	}
	
	// Parameterized constructor      
    BST::BST(int& element) {
		root = new BSTNode(element);
		this->elementCount = 1;
	}               

    // Copy constructor  
	BST::BST(const BST& aBST)  
	{
		//only shallow copy, not deep
		root = aBST.root;
		this->elementCount = aBST.elementCount;
	}

	// Destructor  
	BST::~BST() {
		// If binary search tree is empty, break
		if(this->elementCount <= 0) {
			return;
		}

		// Recursively delete all nodes
		this->removeAll(this->root);
    }                     
	
	
/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.	
	// Time efficiency: O(1)	
	unsigned int BST::getElementCount() const {		
		return this->elementCount;
	}
	

/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
	void BST::insert(const int& newElement) {

	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			this->root = new BSTNode(newElement);
			this->elementCount++;
		}
		else {
			this->insertR(newElement, root);
		}
  	   return;
  	}

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
	bool BST::insertR(const int& anElement, BSTNode* current) { 
		// if new element is less than current node, go left
		if(anElement < current->element) {
			// if left child is null, add new element as left child
			if(!current->hasLeft()) {
				this->makeNodeIfEmpty(current, anElement, true);
				return true;
			}
			// if left child is not null, go left
			else {
				return this->insertR(anElement, current->left);
			}
		}
		// if new element is greater or equal than current node
		else {
			// if right child is null, add new element as right child
			if(!current->hasRight()) {
				this->makeNodeIfEmpty(current, anElement, false);
				return true;
			}
			// if right child is not null, go right
			else {
				return this->insertR(anElement, current->right);
			}
		}
	}

	// Description: Construct new node from the given element and connect the value
	void BST::makeNodeIfEmpty(BSTNode* current, const int& targetElement, const bool isLeft) {
		if (current == NULL || (current->hasLeft() && current->hasRight())) {
			return;
		}
		if (isLeft) {
			current->left = new BSTNode(targetElement);
			this->elementCount++;
		}
		else {
			current->right = new BSTNode(targetElement);
			this->elementCount++;
		}
		return;
	}

    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
    int& BST::retrieve(const int& targetElement) const {
	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");
		
		// Otherwise, search for it		
		int& translated = retrieveR(targetElement, root);
		return translated;
	}


    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    int& BST::retrieveR(const int& targetElement, BSTNode* current) const {
		if (current == NULL) {
			throw ElementDoesNotExistException("Element does not exist in the data collection.");
		}
		else if(current->element == targetElement) {
			return current->element;
		}
		else if(targetElement < current->element) {
			return retrieveR(targetElement, current->left);
		}
		else {
			return retrieveR(targetElement, current->right);
		}
	} // end of retrieveR
				

    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)		
	void BST::traverseInOrder(void visit(const int&)) const {
		// Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);
		return;
	}

    // Description: Recursive in order traversal of a binary search tree.	
	void BST::traverseInOrderR(void visit(const int&), BSTNode* current) const {
		if (current == NULL) {
			return;
		}
		else {
			traverseInOrderR(visit, current->left);
			visit(current->element);
			traverseInOrderR(visit, current->right);
		}
	}
	
	// Description: Recursively deletes all nodes in the binary search tree.
	void BST::removeAll(BSTNode* targetElement) {
		// If the target element is null, break the function
		if (this->elementCount <= 0) {
			return;
		}

		// If left and right node are both NULL, delete the node
		if(targetElement->hasLeft() && targetElement->hasRight()) {
			removeAll(targetElement->left);
			removeAll(targetElement->right);
		}
		// If right node exist, goto right node and execute the function with the right node
		else if(targetElement->hasRight() && !targetElement->hasLeft()) {
			BSTNode* temp = targetElement->right;
			this->removeAll(temp);
			targetElement->right = NULL;
		}
		else if(targetElement->hasLeft() && !targetElement->hasRight()) {
			BSTNode* temp = targetElement->left;
			this->removeAll(temp);
			targetElement->left = NULL;
		}
		delete targetElement;
		return;
	}

	// Question 1
	int BST::nodesCount() const {
		if(this->elementCount == 0) {
			return 0;
		}
		return nodesCountR(root);
	}

	int BST::nodesCountR(BSTNode* current) const {
		if(current == NULL) {
			return 0;
		}
		return 1 + nodesCountR(current->left) + nodesCountR(current->right);
	}



	// Question 2
	int BST::min() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return minR(this->root);
	}

	int BST::minR(BSTNode* current) const {
		if (current->hasLeft()) {
			return minR(current->left);
		}
		return current->element;
	}

	// Question 3
	// Description: Find the number of even elements in the binary search tree.
	int BST::evenCount() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return evenCountR(this->root);
	}

	int BST::evenCountR(BSTNode* current) const {
		if (current == NULL) {
			return 0;
		}

		// If the current node is even, add 1 to the count
		int isEven = (current->element + 1) % 2;

		return isEven + evenCountR(current->left) + evenCountR(current->right);
	}

	// Question 4
	// Description: Find the number of odd elements in the binary search tree.
	int BST::oddCount() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return oddCountR(this->root);
	}

	int BST::oddCountR(BSTNode* current) const {
		if(current == NULL) {
			return 0;
		}

		int isOdd = current->element % 2;

		return isOdd + oddCountR(current->left) + oddCountR(current->right);
	}

	// Question 5
	unsigned int BST::duplicateCount(const int targetElement) {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return duplicateCountR(this->root, targetElement);
	}

	unsigned int BST::duplicateCountR(BSTNode* current, const int targetElement) {
		if (current == NULL) {
			return 0;
		}

		// If the current node is the target element, add 1 to the count
		int isDuplicate = (current->element == targetElement);

		return isDuplicate + duplicateCountR(current->left, targetElement) + duplicateCountR(current->right, targetElement);
	}

	// Question 6
	int BST::height() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return heightR(this->root);
	}

	int BST::heightR(BSTNode* current) const {
		if (current == NULL) {
			return 0;
		}

		int leftHeight = heightR(current->left);
		int rightHeight = heightR(current->right);

		// Return the larger height
		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	}

	// Question 7
	int BST::sum() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return sumR(this->root);
	}

	int BST::sumR(BSTNode* current) const {
		if (current == NULL) {
			return 0;
		}

		return current->element + sumR(current->left) + sumR(current->right);
	}

	// Question 8
	double BST::average() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		return sum() / (double) this->nodesCount();
	}

	// Question 9
	void BST::printInReverseOrder() const {
		if (this->elementCount == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		printInReverseOrderR(this->root);
	}

	// NOT SURE
	void BST::printInReverseOrderR(BSTNode* current) const {
		if (current == NULL) {
			return;
		}

		printInReverseOrderR(current->right);
		cout << current->element << " ";
		printInReverseOrderR(current->left);
	}