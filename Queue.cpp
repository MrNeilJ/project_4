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

void Queue::addBack(Creature* val) {
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

void Queue::addFront(Creature*val, int teamInput) {
	if (front == nullptr) {
		front = new QueueNode(val, nullptr, nullptr);
		front->team = teamInput;
	}
	else {
		QueueNode* queuePtr = new QueueNode(val, front, nullptr);
		queuePtr->team =teamInput;
		front = queuePtr;
		front->next->prev = front;



	}
}


Creature* Queue::getFront() {
	if (front) {
		return front->value;
	}
	else {
		return nullptr;
	}
}

/*void Queue::removeFront() {
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
}*/

Creature* Queue::removeFront() {
	if (front == back){
		QueueNode* nodePtr = front;
		front = nullptr;
		back = nullptr;

		// Return the creature that was removed
		return nodePtr->value;
	}
	else {
		QueueNode* nodePtr = front;
		front->next->prev = back;
		back->next = front->next;
		// delete front;
		front = back->next;


		return nodePtr->value;
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
		while (nodePtr != nullptr) {
			// Print the value in the current node
			std::cout << "Team " << (nodePtr->team + 1) << ": " << nodePtr->value->getName() << std::endl;
			// Move to the next node
			nodePtr = nodePtr->next;
		}
	}
	else {
		std::cout << "Nothing in this list.";
		return;
	}


}

void Queue::moveFront() {
	/*// Save the current stats of the front pointer
	QueueNode *nodePtr = front;*/
	// Move the front pointer to the next item in the list
	front = front->next;
	back  = front->prev;

	/*// Set the now current front pointer to the previous nodePtr
	front->prev = nodePtr;

	// Set the previous head value to now point to the head
	nodePtr->next = front;
*/

}

void Queue::clearSet() {
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

