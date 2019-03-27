#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Player
{
protected:
	string playerName;
	vector<Card> hand;
	int handValue;
public:
	Player();
	Player(string);
	~Player();
	string getName();
	void addCard(Card);
	void removeCards();
	void getHand();	
	int getHandValue();
};

#endif