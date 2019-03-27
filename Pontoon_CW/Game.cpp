#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

void Game::newDeal(Deck *deck, Player &player, Dealer &dealer, int &cardCounter)
{
	player.removeCards(); //remove cards from previous round
	dealer.removeCards(); //for dealer as well

	if (cardCounter > 40){ 
		deck->shuffle();
		cardCounter = 0;
	}

	player.addCard(deck->selectCard(cardCounter)); 
	cardCounter++;
	dealer.addCard(deck->selectCard(cardCounter));
	cardCounter++;
	player.addCard(deck->selectCard(cardCounter));
	cardCounter++;
	dealer.addCard(deck->selectCard(cardCounter));
	cardCounter++;		

	gameInfo(player, dealer);
	
	dealerPlay(deck, dealer, cardCounter);	
	if (whoWin(player, dealer) == 2){
		gameSummary(player, dealer);
		cout << endl << "Dealer Lost" << endl << "You win " << endl << endl;
		

		cout << endl << "New Deal" << endl;
		newDeal(deck, player, dealer, cardCounter);
	}
}


void Game::dealerPlay(Deck *deck, Dealer &dealer, int cardCounter){
		dealer.addCard(deck->selectCard(cardCounter));
		cardCounter++;
}



bool Game::winner(Player &player, Dealer &dealer)
{
	if (player.getHandValue() < 21 && player.getHandValue() < dealer.getHandValue()){
		cout << endl << "Dealer won" << endl << "You lost " << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() < 21 && player.getHandValue() == dealer.getHandValue()){
		gameSummary(player, dealer);
		cout << endl << "Tie!" << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() < 21 && player.getHandValue() > dealer.getHandValue()){
		gameSummary(player, dealer);
		cout << endl << "Winner!" << endl << "You win " << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() > 21){
		gameSummary(player, dealer);
		cout << endl << "Dealer won" << endl << "You lost " << endl << endl << "#NEW GAME#" << endl;
		return true;
	}	
	else if (player.getHandValue() == 21){
		gameSummary(player, dealer);
		cout << endl << "BlackJack!" << endl << "You win " << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (dealer.getHandValue() > 21){
		gameSummary(player, dealer);		
		cout << endl << "Dealer lost" << endl << "You win " << endl << endl << "#NEW GAME#" << endl;
		return true;
	}	
}

bool Game::winInFirst(Player &player, Dealer &dealer)
{
	if (player.getHandValue() > 21){
		gameSummary(player, dealer);
		cout << endl << "Dealer won" << endl << "You lost "  << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() == 21){
		gameSummary(player, dealer);
		cout << endl << "BlackJack!" << endl << "You win "  << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (dealer.getHandValue() > 21){
		gameSummary(player, dealer);
		cout << endl << "Dealer lost" << endl << "You win "  << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
}

void Game::gameInfo(Player &player, Dealer &dealer)
{
	cout << "Player " << player.getName() << endl << endl << "Cards on hand: " << endl;

	player.getHand(); 
	cout << "Score: " << player.getHandValue() << endl;

	cout << endl << "Dealer's hand: " << endl;
	dealer.showOne(); 
}

void Game::gameSummary(Player &player, Dealer &dealer)
{

	cout << "Player " << player.getName()  << endl << endl << "Cards on hand: " << endl;

	player.getHand();  
	cout << "Score: " << player.getHandValue() << endl;

	cout << endl << "Dealer's hand: " << endl;
	dealer.getHand();
	cout << "Score: " << dealer.getHandValue() << endl;
}

int Game::whoWin(Player &player, Dealer &dealer){
	if (player.getHandValue() > 21) return -2; 
	else if (dealer.getHandValue() > 21) return 2; 
	else if (player.getHandValue() == 21) return 3; 
	else if (player.getHandValue() < 21 && player.getHandValue() > dealer.getHandValue()) return 1; 
	else if (player.getHandValue() < 21 && player.getHandValue() == dealer.getHandValue()) return 0; 
	else if (player.getHandValue() < 21 && player.getHandValue() < dealer.getHandValue()) return -1; 
}