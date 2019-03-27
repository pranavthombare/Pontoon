#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
using namespace std;

class Game
{
public:
	void newDeal(Deck*, Player&, Dealer&, int&);
	void dealerPlay(Deck*, Dealer&, int);
	void gameInfo(Player&, Dealer&);	
	void gameSummary(Player&, Dealer&);
	int whoWin(Player&, Dealer&);
	bool winner(Player&, Dealer&);
	bool winInFirst(Player&, Dealer&);
};

#endif

