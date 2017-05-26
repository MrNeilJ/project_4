/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the queue file for the functionality within
 * the main application.  This class allows us to build a queue and
 * items into it one by one, and also remove and print the items to the
 * screen.
 **************************************************************/

#include <iostream>
#include "Queue.hpp"
#include "Vampire.hpp"

Queue::Queue() {
	front 	= nullptr;
	back 	= nullptr;
}

Queue::~Queue() {
	QueueNode *nodePtr = front;
	while (nodePtr != back) {
// Mark node for preparation to delete
		QueueNode *garbage = nodePtr;

// Move pointer to next item
		nodePtr = nodePtr->next;

// Delete old node
		delete garbage;
	}
	delete back;
	front = nullptr;
	back = nullptr;
}

void Queue::addBack(Creature*val) {
	if (front == nullptr) {
		front = new QueueNode(val, back, back);
	}
	else if (back == nullptr) {
		back = new QueueNode(val, front, front);
		front->next = back;
		front->prev = back;
	}
	else {
		QueueNode* queuePtr = new QueueNode(val, front, back);
		back->next 	= queuePtr;
		front->prev = queuePtr;
		back = queuePtr;
	}
}

Creature* Queue::getFront() {
	if (front) {
		return front->value;
	}
	else {
		std::cout << "No item to show." << std::endl;
	}
}

void Queue::removeFront() {
	if (front == back){
		front = nullptr;
		back = nullptr;
	}
	else {
		front->next->prev = back;
		back->next = front->next;
		delete front;
		front = back->next;
	}

}

/**************************************************************
 *                  Queue::displayList()
 *	Prints the items out from first item to last item.  If there
 *	is nothing in the list then notify the user
 **************************************************************/
void Queue::displayList() {
	if (front) {
		QueueNode *nodePtr = front;
		while (nodePtr != back) {
			// Print the value in the current node
			std::cout << nodePtr->value << " ";
			// Move to the next node
			nodePtr = nodePtr->next;
		}
		if (back) {
			std::cout << nodePtr->value << " ";
		}
	}
	else {
		std::cout << "Nothing in this list.";
		return;
	}


}