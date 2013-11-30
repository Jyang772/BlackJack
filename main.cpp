#include <iostream>
#include "Card.h"
#include "Deck.h"
using namespace std;

//FUNCTION PROTOTYPE
int computeHandValue(Card hand[], int howMany);

int main() {
	//VARIABLES
	Deck cardDeck;		//DECK OF CARDS
	Card playerHand[8];	//HOLDS THE PLAYER HAND         //Creates eight Card objects
	Card dealerHand[8];	//HOLDS THE DEALER HAND
	int playerHowmany = 0;
	int dealerHowmany = 0;

	cout << "Welcome to the game of Blackjack" << endl;

	//TASK 1: SHUFFLE THE DECK OF CARDS
	cardDeck.shuffle();
	char playGame;
	cout << "Do you wish to play a game? Enter Yy  ";
	cin >> playGame;

	while (playGame == 'Y' || playGame == 'y'){
		cout << "\n\n***** N E W     G A M E *****"
			<< "\n-------------------------------" << endl;

		cardDeck.debug();

		//TASK 2: DEAL TWO CARDS TO THE DEALER.  DISPLAY ONE OF THE CARDS
		dealerHand[0] = cardDeck.deal();
		dealerHand[1] = cardDeck.deal();
		dealerHowmany = 2;
		cout << "\n\nThe dealer had one card as follows: \n\t";
		dealerHand[0].display();

		//TASK 3:  DEAL TWO CARDS TO THE PLAYER.  DISPLAY BOTH CARDS
		playerHand[0] = cardDeck.deal();
		playerHand[1] = cardDeck.deal();
		playerHowmany = 2;
		cout << "\n\n\nYou have two cards as follows:  \n\t";
		playerHand[0].display();
		cout << "\n\t";
		playerHand[1].display();

		//TASK 4:  STAY OR HIT
		bool hit = 0;
		do {
			cout << "\nYour hand value is "
				<< computeHandValue(playerHand, playerHowmany);
			cout << ".  Stay (0) or hit (1)?";
			cin >> hit;
			if (hit) {
				playerHand[playerHowmany] = cardDeck.deal();
				cout << "\t";
				playerHand[playerHowmany++].display();
			}
		} while (hit);

		//TASK 5:  COMPLETE THE DEALER HAND
		cout << "\n\nThe dealer's hand is as follows: ";
		cout << "\n\t"; dealerHand[0].display();
		cout << "\n\t"; dealerHand[1].display();
		if (computeHandValue(dealerHand, dealerHowmany) < 12) {
			dealerHand[dealerHowmany] = cardDeck.deal();
			cout << "\n\t";
			dealerHand[dealerHowmany++].display();
		}

		//TASK 6:  DETERMINE THE WINNER
		int dealerScore = computeHandValue(dealerHand, dealerHowmany);
		int playerScore = computeHandValue(playerHand, playerHowmany);
		cout << "\n\nThe dealer score is " << dealerScore << endl;
		cout << "Your score is " << playerScore << endl;
		if (playerScore > 21)
			cout << "Sorry, you exceeded 21." << endl;
		else if (playerScore == 21)
			cout << "You win.  You hit 21." << endl;
		else if (dealerScore == 21)
			cout << "The dealer has hit 21.  You lose" << endl;
		else if (dealerScore > 21)
			cout << "The dealer busts. You win." << endl;
		else if (dealerScore >= playerScore)
			cout << "The dealer wins this round." << endl;
		else
			cout << "You win this round." << endl;

		//TASK 7:  ANOTHER GAME?
		cout << "Do you wish to play another game? Enter Yy  ";
		cin >> playGame;
	}

	return 0;
}

int computeHandValue(Card hand[], int howMany){
	//VARIABLES
	int handValue = 0; 	//INITIALIZE HAND TO ZERO
	bool noAces = true; 	//ASSUME THERE ARE NO ACES

	//EXAMINE EACH CARD AND SUM THE VALUE
	for (int i = 0; i < howMany; i++) {
		int cardValue = hand[i].getValue();
		handValue += cardValue;
		if (cardValue == 1) {
			noAces = false;
		}

			
	}
	if (!noAces&&handValue + 10 <= 21) {
		handValue += 10;
	}
	return handValue;
}
