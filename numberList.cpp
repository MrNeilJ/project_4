/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the file that assists with the creation
 * of the linked list.  In this file we are able to create a
 * stucture for list items and link them together.  We can even
 * add, and remove items from the front and back of the list.
 **************************************************************/

#include <iostream>
#include "numberList.hpp"
#include "Creature.hpp"


/**************************************************************
 *                  numberList::numberList()
 *	Constructor for the object, builds the object with nullptrs
 **************************************************************/
numberList::numberList() {
	head = nullptr;
	tail = nullptr;
}

/**************************************************************
 *                  numberList::~numberList()
 *	Destructor for the object, loops through all of the items
 *	linked together, freeing up their memory
 **************************************************************/
numberList::~numberList() {
	ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		// Mark node for preparation to delete
		ListNode *garbage = nodePtr;

		// Move pointer to next item
		nodePtr = nodePtr->next;

		// Delete old node
		delete garbage;
	}
}


/**************************************************************
 *                  numberList::add()
 *	Generic add feature, was designed to allow the user to add
 *	an item to the end of a single linked list.
 **************************************************************/
void numberList::add(Creature * number) {
	if (head == nullptr) {
		head = new ListNode(number, nullptr, head);
	}
	else {
		ListNode *nodePtr = head;
		while (nodePtr->next != nullptr){
			nodePtr = nodePtr->next;
		}

		nodePtr->next = new ListNode(number, nullptr, nodePtr);

	}
}

/**************************************************************
 * HEAD FUNCTIONS
 **************************************************************/
/**************************************************************
*                  numberList::addHead()
*	Adds the item to the head of the linked list and then links
 *	it to the rest of the linked list without losing it.
**************************************************************/
void numberList::addHead(Creature* number) {
	if (head == nullptr) {
		head = new ListNode(number, tail, nullptr);
		tail = head;
	}
	else {
		ListNode *nodePtr = head;
		head = new ListNode(number, nodePtr);
		nodePtr->prev = head;
	}
}

/**************************************************************
 *                  numberList::removeHead()
 *	Removes the first item on the linked list and moves the head
 *	pointer to the item next to it.
 **************************************************************/
void numberList::removeHead() {
	ListNode 	*nodePtr;

	if (!head){
		return;
	}
	else if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else{
		// Mark the old head location for later
		nodePtr = head;

		// Move the location of the head location up one spot
		head = head->next;
		head->prev = nullptr;

		// Delete the old head location
		delete nodePtr;
	}

}

/**************************************************************
 * TAIL FUNCTIONS
 **************************************************************/
/**************************************************************
*                  numberList::addTail()
*	Adds the item to the tail of the linked list and then links
*	it to the rest of the linked list without losing it.
**************************************************************/
void numberList::addTail(Creature* number) {
	if (tail == nullptr) {
		tail = new ListNode(number, tail, nullptr);
	}
	else {
		ListNode *nodePtr = head;
		head = new ListNode(number, nodePtr);
	}
}

/**************************************************************
 *                  numberList::removeTail()
 *	Removes the last item on the linked list and moves the tail
 *	pointer to the item before it.
 **************************************************************/
void numberList::removeTail() {
	ListNode 	*nodePtr;

	if (!tail){
		return;
	}

	else if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else{
		// Mark the old head location for later
		nodePtr = tail;

		// Move the location of the head location up one spot
		tail = tail->prev;
		tail->next = nullptr;

		// Delete the old head location
		delete nodePtr;
	}
}

/**************************************************************
 * DISPLAY FUNCTIONS
 **************************************************************/
/**************************************************************
 *                  numberList::displayList()
 *	Prints the items out from first item to last item.  If there
 *	is nothing in the list then notify the user
 **************************************************************/
void numberList::displayList() const {
	if (!head) {
		std::cout << "Nothing in this list.";
		return;
	}
	ListNode *nodePtr = head;
	while (nodePtr) {
		// Print the value in the current node
		std::cout << nodePtr->value->getName() << std::endl;
		// Move to the next node
		nodePtr = nodePtr->next;
	}
}

/**************************************************************
 *                  numberList::displayListReverse()
 *	Prints the items out from last item to first item.  If there
 *	is nothing in the list then notify the user
 **************************************************************/
void numberList::displayListReverse() const {
	if (!head) {
		std::cout << "Nothing in this list.";
		return;
	}
	ListNode *nodePtr = tail;
	while (nodePtr) {
		// Print the value in the current node
		std::cout << nodePtr->value << " ";
		// Move to the next node
		nodePtr = nodePtr->prev;
	}
}

void numberList::clearSet() {
	ListNode *nodePtr = head;
	while (nodePtr != nullptr) {
		// Mark node for preparation to delete
		ListNode *garbage = nodePtr;

		// Move pointer to next item
		nodePtr = nodePtr->next;

		// Delete old node
		delete garbage;
		head = nullptr;
		tail = nullptr;
	}
}
