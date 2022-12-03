#include <iostream>
#include <vector>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include "game.h"
#include "mechanics.h"

vector<Card> cards;

void single(User &usr) {
    int count;
    bool play = true;

    while (play) {
      cards.clear();

      int *p_inv = store(usr);

      randomCard();   // initial card
      count = 0;
      while (count < 7) {
        cout << "Streak: " << count << endl;

        printCard();

        if (cards.size() == 52) {   // player wins if all cards are drawn
          play = levelUp(usr, p_inv);
          break;
        }

        randomCard();

        Card currentcard = cards[cards.size()-2];
        Card nextcard = cards[cards.size()-1];

        // use card revealer?
        bool reveal = cardRevealer(p_inv);

        if (reveal) {
          cout << "\033[0;36m You used a Card Revealer. \033[0m" << endl;
          count++;
          correct(usr, p_inv); // money and score can be added after using card revealer
        }
        else {
          int result;
      		if (currentcard.rank_idx > 1) {
            while (1) {
            result = GuessSize(currentcard, nextcard);
            if (result != -1) // if guessed wrong then end
              break;
            }
          }
      		else {
            while (1) {
            result = GuessColour(nextcard);
            if (result != -1) // if guessed wrong then end
              break;
            }
          }

          bool gameover = result != 0;
      		if (gameover) {
            printCard();
            bool resurrect = gameOver(usr, result); // resurrect?
            if (!resurrect) {
              play = false;
              break; // if do not resurrect, game end
            }
          }
          else {
            count++;
            correct(usr, p_inv);
          }
        }

      }

    if (count == 7) { // level up when guessed correctly for 7 consecutive times
      cout << "Streak: " << count << endl;
      printCard();
      play = levelUp(usr, p_inv);
    }
    delete p_inv;
  }
}

bool sameCard(int card_idx) { //if the card size of the current card and the next card is the same, the player loses
  for (int i = 0; i < cards.size(); i++)
    if (cards[i].idx == card_idx)
      return 1;
  return 0;
}

void randomCard() {
  srand(time(NULL)); // seeding the pseudo-random generator
  int card_idx = rand() % 52;   // generate random card

  while (sameCard(card_idx)) //loop until no same card is generated
    card_idx = rand() % 52;

  Card c(card_idx);
  cards.push_back(c);   // add card to cards
}

void printCard() {
  cards[cards.size()-1].print_card();
}
