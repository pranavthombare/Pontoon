#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>

#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Game.h"

string playerName;

int main(void){
	srand(time(0));

	Game game;
	Deck *deck = new Deck();
	int cardCounter = 0;
	int choice;
	int ctr=2;
	int deal = 0;
	int won=0,lost=0;
	ofstream file;
    auto game_begin = chrono::system_clock::to_time_t(chrono::system_clock::now()); 


	cout << "What is your name?: ";
	cin >> playerName;	
	Player player(playerName);
	Dealer dealer;

	deck->shuffle();

	game.newDeal(deck, player, dealer, cardCounter);
	
	bool ans=true;
	while(ans){		
		cout << endl << "Twist (1)" << endl << "Stick (2)" << endl << "Exit (3)"<< endl;
		do{
			cin >> choice;
		} while (!(choice > 0 && choice < 4));

		switch (choice)	{

	case 1:{
			player.addCard(deck->selectCard(cardCounter));
			cardCounter++;
			game.gameInfo(player, dealer);
			if (game.whoWin(player, dealer) == (-2)) {
			game.gameSummary(player, dealer);
			cout << endl << "Dealer won" << endl << "You lost " << endl;
			lost++;
			cout << endl << "#NEW GAME#" << endl;
			game.newDeal(deck, player, dealer, cardCounter);
			deal++;
			}
			else if (game.whoWin(player, dealer) == 2) {
			game.gameSummary(player, dealer);
			cout << endl << "Dealer lost" << endl << "You win " << endl;
			won++;
			cout << endl <<"#NEW GAME#" << endl;
			game.newDeal(deck, player, dealer, cardCounter);
			deal++;
			}
			
		}break;

	case 2:{
			game.gameSummary(player, dealer);
			if (game.whoWin(player, dealer) == 1){
			cout << endl << "Winner!" << endl << "You win "<< endl;
			won++;
			cout << endl << "#NEW GAME#" << endl;
			game.newDeal(deck, player, dealer, cardCounter);
			deal++;
			}

			else if (game.whoWin(player, dealer) == 0){
			cout << endl << "Tie!" << endl;
			cout << endl << "#NEW GAME#" << endl;
			game.newDeal(deck, player, dealer, cardCounter);
			deal++;
			}

			else if (game.whoWin(player, dealer) == (-1)){
			cout << endl << "Dealer won" << endl << "You lost " << endl;
			lost++;
			cout << endl << "#NEW GAME#" << endl;
			game.newDeal(deck, player, dealer, cardCounter);
			deal++;
			}

			else if (game.whoWin(player, dealer) == 3) {
			game.gameSummary(player, dealer);
			cout << endl << "Pontoon!" << endl << "You win " << endl;
			won++;
			cout << endl << "#NEW GAME#" << endl;
			game.newDeal(deck, player, dealer, cardCounter);
			deal++;
			}

		}break;

			
		
		 case 3:{ans = false;
		 
		 
			 break;
			 
		 }

		}
	} 

    auto game_end = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	system("clear");
	cout << "\n\nGame Started at"<<ctime(&game_begin)<<endl;
	cout << "Game Ended at"<<ctime(&game_end)<<endl;
	cout << "Rounds = "<<deal<<endl;
	cout << "Won = "<<won<<endl;
	cout << "Lost = "<<lost<<endl;
	cout << "";

	file.open ("Pontoon_Log.txt");
	file << "\n\nGame Started at"<<ctime(&game_begin)<<endl;
	file << "Game Ended at"<<ctime(&game_end)<<endl;
	file << "Rounds = "<<deal<<endl;
	file <<	"Won = "<<won<<endl;
	file <<	"Lost = "<<lost<<endl;
	file << "";
	file.close();
	cout<<"Logs generated"<<endl;
	
}

