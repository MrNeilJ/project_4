//
// Created by Neil on 5/2/2017.
//

#ifndef PROJECT_3_DICE_HPP
#define PROJECT_3_DICE_HPP


class Dice {
private:
	int sides;
	int numDie;
public:
	// Constructors
	Dice();
	Dice(int, int);

	// Member function to roll the dice
	int roll();
};



#endif //PROJECT_3_DICE_HPP
