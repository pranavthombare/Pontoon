#include "Player.h"
#include <iostream>


Player::Player(){}

Player::Player(string name){
	playerName = name;
	handValue = 0;
}

Player::~Player(){}

string Player::getName(){
	return playerName;
}

void Player::addCard(Card card){
	hand.push_back(card);
}

void Player::removeCards(){
	hand.clear();
}

int Player::getHandValue(){
	handValue = 0;
	for (int i = 0; i < hand.size(); i++){
		handValue += hand[i].getValue();
	}
	return handValue;
}

void Player::getHand(){
	
	for (int i = 0; i < hand.size(); i++){
		std::cout << hand[i].getCard() << endl;
	}
}

