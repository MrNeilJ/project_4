//
// Created by Neil on 5/9/2017.
//

#ifndef LAB_6_LISTNODE_HPP
#define LAB_6_LISTNODE_HPP

#include "Creature.hpp"

class numberList {
private:
	struct ListNode {
		Creature* value;
		ListNode *next;
		ListNode *prev;
		//
		ListNode(Creature* value1, ListNode *next1 = nullptr, ListNode *prev1 = nullptr) {
			value = value1;
			next = next1;
			prev = prev1;
		}
	};
	ListNode *head;
	ListNode *tail;

public:
	// Constructor
	numberList();

	// Destructor
	~numberList();
	void add(Creature* number);

	// Head Functions
	void addHead(Creature* number);
	void removeHead();

	// Tail Functions
	void addTail(Creature* number);
	void removeTail();

	// Display functions
	void displayList() const;
	void displayListReverse() const;

	void clearSet();
};


#endif //LAB_6_LISTNODE_HPP
