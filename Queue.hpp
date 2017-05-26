/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the header queue file for the functionality within
 * the main application.  This class allows us to build a queue and
 * items into it one by one, and also remove and print the items to the
 * screen.
 **************************************************************/

#ifndef LAB_7_QUEUE_HPP
#define LAB_7_QUEUE_HPP
#include "Creature.hpp"


class Queue {
private:
	struct QueueNode {
		Creature* value;
		QueueNode* next;
		QueueNode* prev;

		// Constructor for the QueueNode Struct
		QueueNode(Creature *value1, QueueNode* next1 = nullptr, QueueNode* prev1 = nullptr) {
			value = value1;
			next = next1;
			prev = prev1;
		}
	};

	QueueNode* front;
	QueueNode* back;

public:
	Queue();
	~Queue();
	void addBack(Creature *val);	// Puts on item at the end of the queue
	Creature* getFront();		// returns the value at the front of the queue
	void removeFront();		// removes the front item in the structure
	void displayList();
};


#endif //LAB_7_QUEUE_HPP
